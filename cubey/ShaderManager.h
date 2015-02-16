#pragma once

#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <set>
#include "GL/glew.h"

#include "ShaderProgram.h"
#include "SingletonBase.h"

namespace cubey {

	class ShaderManager : public SingletonBase<ShaderManager> {
	public:
		class BufferCleaner {
		public:
			BufferCleaner() {
				files_.clear();
			}
			~BufferCleaner() {
				Clear();
			}
			void Clear();

		private:
			static std::set<std::string> files_;

			friend ShaderManager;
		};

		ShaderProgram* CreateProgram(const std::string& program_key);
		ShaderProgram* GetProgram(const std::string& program_key);
		void DestroyProgram(const std::string& program_key);
		void UnloadFile(const std::string& file_name);

	private:
		struct ShaderFile {
			std::unordered_map<std::string, std::string> blocks;
		};

		void LoadFile(const std::string& file_name);
		std::string GetInclude(const std::string& file_name);
		std::vector<std::string> Tokenize(const std::string& str, const std::string& delimiters = ".");
		GLenum GetShaderType(const std::string& shader_key);

		//std::string current_file_;
		//std::stringstream buffer_;
		//std::set<std::string> directives_;
		std::unordered_map<std::string, ShaderFile> files_;
		std::unordered_map<std::string, ShaderProgram*> programs_;
	};
}