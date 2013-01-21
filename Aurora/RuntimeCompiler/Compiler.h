//
// Copyright (c) 2010-2011 Matthew Jack and Doug Binks
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.

#pragma once

#include <string>
#include <vector>

#include "FileSystemUtils.h"

class PlatformCompilerImplData;
struct ICompilerLogger;

class Compiler
{
public:
	Compiler();
	~Compiler();
	void Initialise( ICompilerLogger * pLogger );

	const std::string GetObjectFileExtension() const;
	void RunCompile( const std::vector<FileSystemUtils::Path>& filesToCompile,
					 const std::vector<FileSystemUtils::Path>& includeDirList,
					 const std::vector<FileSystemUtils::Path>& libraryDirList,
					 const std::vector<FileSystemUtils::Path>& linkLibraryList,
					 const char* pCompileOptions,
					 const char* pLinkOptions,
					 const FileSystemUtils::Path& outputFile );
	bool GetIsComplete() const;
private:
	PlatformCompilerImplData* m_pImplData;
};
