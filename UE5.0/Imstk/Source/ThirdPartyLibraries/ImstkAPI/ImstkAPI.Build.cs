using System.IO;
using System.Collections.Generic;
using UnrealBuildTool;

public class ImstkAPI : ModuleRules
{
    public ImstkAPI(ReadOnlyTargetRules Target) : base(Target) {
        string ImstkVersion = "6.0";

        bUseRTTI = true;
        bLegacyPublicIncludePaths = true;
        Type = ModuleType.External;
        if (Target.Platform == UnrealTargetPlatform.Win64) {

            PrivateDependencyModuleNames.AddRange(
                 new string[]
                 {
                //"IntelTBB",
                "OpenVR"
                 }
             );

            // Unreal has separate version of eigen, however it has differences from iMSTK's version
            PublicIncludePaths.AddRange(
                 new string[]{
                 //"ThirdParty/Eigen"
                 }
             );


            string PlatformDir = Target.Platform.ToString();

            string IncPath = Path.Combine(ModuleDirectory, "include");
            PublicSystemIncludePaths.Add(IncPath);

            IncPath = Path.Combine(ModuleDirectory, "include/iMSTK-" + ImstkVersion);
            PublicIncludePaths.Add(IncPath);

            IncPath = Path.Combine(ModuleDirectory, "include/eigen3");
            PublicIncludePaths.Add(IncPath);

            IncPath = Path.Combine(ModuleDirectory, "include/vtk-9.1");
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

            //RuntimeDependencies.Add();

            List<string> RuntimeModuleNames = new List<string>();

            FileInfo[] dllFiles = d.GetFiles("*.dll");

            foreach (FileInfo file in dllFiles) {
                // if (file.Name == "tbb12.dll") // Skip, already included with Unreal Engine
                //    continue;
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





            PublicDefinitions.Add("WITH_IMSTKAPI=1");
            PublicDefinitions.Add("__WINDOWS__");

            // Silence Eigen c++17 warnings
            PublicDefinitions.Add("_SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING");
        }
    }
}