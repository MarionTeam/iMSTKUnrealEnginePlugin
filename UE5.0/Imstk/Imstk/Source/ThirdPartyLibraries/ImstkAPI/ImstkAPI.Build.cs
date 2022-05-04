using System.IO;
using System.Collections.Generic;
using UnrealBuildTool;

public class ImstkAPI : ModuleRules
{
    public ImstkAPI(ReadOnlyTargetRules Target) : base(Target) {
        bUseRTTI = true;
        bLegacyPublicIncludePaths = true;
        Type = ModuleType.External;
        if (Target.Platform == UnrealTargetPlatform.Win64) {
            string PlatformDir = Target.Platform.ToString();

            string IncPath = Path.Combine(ModuleDirectory, "include");
            PublicSystemIncludePaths.Add(IncPath);

            // this is required because imstk geometry requires files in eigen3 but does not reference them in the subdirectory
            // TODO: This also means that this folder is technically included twice (maybe just change the file structure)
            IncPath = Path.Combine(ModuleDirectory, "include/eigen3");
            PublicIncludePaths.Add(IncPath);

            string LibPath = Path.Combine(ModuleDirectory, "lib");
            //PublicLibraryPaths.Add(LibPath);

            DirectoryInfo d = new DirectoryInfo(LibPath);
            FileInfo[] Files = d.GetFiles("*.lib");

            foreach (FileInfo file in Files) {
                PublicAdditionalLibraries.Add(Path.Combine(LibPath, file.Name));
                //System.Console.WriteLine(File.Name);
            }

            //FileInfo[] dllFiles = d.GetFiles("*.dll");
            //string BinaryPath = Path.GetFullPath(Path.Combine(ModuleDirectory, "../../../Binaries/ThirdParty", PlatformDir));
            //foreach (FileInfo dll in dllFiles) {
            //    PublicDelayLoadDLLs.Add(dll.Name);
            //    RuntimeDependencies.Add(Path.Combine(BinaryPath, dll.Name));
            //    //System.Console.WriteLine(BinaryPath);
            //}

            List<string> RuntimeModuleNames = new List<string>();

            FileInfo[] dllFiles = d.GetFiles("*.dll");

            foreach (FileInfo file in dllFiles) {
                if (file.Name == "tbb12.dll") // Skip, already included with Unreal Engine
                    continue;
                RuntimeModuleNames.Add(file.Name);
            }


            foreach (string RuntimeModuleName in RuntimeModuleNames) {
                string ModulePath = Path.Combine(LibPath, RuntimeModuleName);
                if (!File.Exists(ModulePath)) {
                    string Err = string.Format("PROJ SDK module '{0}' not found.", ModulePath);
                    System.Console.WriteLine(Err);
                    throw new BuildException(Err);
                }
                RuntimeDependencies.Add("$(BinaryOutputDir)/" + RuntimeModuleName, ModulePath);
            }

            // Stage Proj data files
           // RuntimeDependencies.Add("$(BinaryOutputDir)/proj-data/*", Path.Combine(LibPath, "proj-data/*"), StagedFileType.SystemNonUFS);



            PublicDefinitions.Add("WITH_IMSTKAPI=1");
            PublicDefinitions.Add("__WINDOWS__");
        }
    }
}