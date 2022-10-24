// StaticLibrary.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "StaticLibrary.h"

#include <cstdio>
#include <iostream>
#include <stdexcept>

#include <azure/storage/blobs.hpp>

using namespace Azure::Storage::Blobs;

// TODO: This is an example of a library function
uint64_t GetBlobSize(std::string containerName, std::string blobName, std::string connectionString)
{
    auto containerClient
        = BlobContainerClient::CreateFromConnectionString(connectionString, containerName);

    containerClient.CreateIfNotExists();

    BlockBlobClient blobClient = containerClient.GetBlockBlobClient(blobName);

    return blobClient.GetProperties().Value.BlobSize; 
}
