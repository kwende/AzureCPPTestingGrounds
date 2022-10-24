#pragma once

using namespace System;

namespace ManagedLibrary {
	public ref class AzureFile
	{
	public:
		AzureFile(String^ blobName, String^ containerName, String^ connectionString); 
		unsigned long long GetFileSize(); 
	private:
		String^ _blobName, ^_containerName, ^_connectionString; 
	};
}
