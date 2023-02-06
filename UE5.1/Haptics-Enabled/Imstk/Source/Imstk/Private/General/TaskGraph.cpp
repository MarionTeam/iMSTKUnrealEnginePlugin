// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskGraph.h"

UTaskGraph::UTaskGraph()
{
}
UTaskGraph::~UTaskGraph()
{
}

#if WITH_EDITORONLY_DATA
void UTaskGraph::Clear() 
{
	Nodes.Empty();
}
#endif