# Steps to reproduce problem

1. Git pull VCPKG from here: https://github.com/microsoft/vcpkg
2. Run .\bootstrap-vcpkg.bat from the VCPKG repo. 
3. Now install the Azure C++ SDK: ./vcpkg.exe install azure-storage-blobs-cpp:x64-windows azure-storage-files-datalake-cpp:x64-windows azure-storage-files-shares-cpp:x64-windows. 
4. We don't use CMAKE for anything, so we're going to just grab the DLL/LIB files directly. We notice the .LIB files generated to: C:\repos\vcpkg\installed\x64-windows\lib. Likewise, 
we notice the include files located at C:\repos\vcpkg\installed\x64-windows\include.
5. We create a new solution (the solution in this repo) that consists of three components: a native static library, a C++/CLR library, and a C# console application. 
6. We copy the LIB and INCLUDE files from where we found them in Step 4 to an EXTERNALS folder in our solution. Since all we're concerned with at this time is building, we leave out the DLLs.
7. We reference the LIB and INCLUDE files from the static library. We then take add code to the static library inspired from https://github.com/Azure/azure-sdk-for-cpp/blob/main/sdk/storage/azure-storage-blobs/samples/blob_getting_started.cpp. 
8. We build this library and notice it builds. 
9. We then reference this static library from the C++/CLR library. We attempt to use it, but notice it doesn't build because of LNK2005 errors regarding the C runtime. 

It's worth noting I tried to build the Azure C++ libraries manually, but ran into same or similar problems. 
