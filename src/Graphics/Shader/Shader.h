#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <unordered_map>

namespace Horus
{
	class Shader
	{
	public:

		Shader(const std::string& vertexPath, const std::string& fragmentPath);
		~Shader();
		
		void Bind();
		void Unbind();

		//metodos para establecer los uniforms 
		void SetInt(const std::string& name, int value);
		void SetFloat(const std::string& name, float value);
		void SetVec2(const std::string& name, const glm::vec2& value);
		void SetVec3(const std::string& name, const glm::vec3& value);
		void SetVec4(const std::string& name, const glm::vec4& value);
		void SetMat4(const std::string& name, const glm::mat4& matrix);

	private:

		//ID del shader
		unsigned int m_RendererID;

		//carga el contenido de un archivo de shader 
		std::string ReadFile(const std::string& filePath);	

		//compila y enlaza los shaders
		unsigned int CompileShader(unsigned int type, const std::string& source);
		unsigned int CreateProgram(const std::string& vertexSource, const std::string& fragmentSource);


		//cache para las ubicaciones de los uniforms
		std::unordered_map<std::string, int> m_UniformLocationCache;

		//obtiene la ubicacion del uniform en el cache para evitar llamadas repetidas
		int GetUniformLocation(const std::string& name);

	};
}









