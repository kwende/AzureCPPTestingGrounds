#include "pch.h"

#include <msclr\marshal_cppstd.h>


#include "ManagedLibrary.h"
#include "StaticLibrary.h"


using namespace ManagedLibrary; 

AzureFile::AzureFile(String^ blobName, String^ containerName, String^ connectionString)
{
	_blobName = blobName; 
	_containerName = containerName; 
	_connectionString = connectionString; 
}
unsigned long long AzureFile::GetFileSize()
{
	msclr::interop::marshal_context context;

	return DoIt(context.marshal_as<std::string>(_containerName),
		context.marshal_as<std::string>(_blobName),
		context.marshal_as<std::string>(_connectionString));
}
