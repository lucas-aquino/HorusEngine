#include "Shader.h"

#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include "../../Utils/Logger/Logger.h"

namespace Horus
{

	Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
	{


	}

	Shader::~Shader()
	{
		glDeleteProgram(m_RendererID);
	}


	void Shader::Bind()
	{
		glUseProgram(m_RendererID);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}
	
	//es un helper que nos ayuda a obtener la ubicacion de los uniforms
	int Shader::GetUniformLocation(const std::string& name) 
	{
		if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		{
			return m_UniformLocationCache[name];
		}

		int location = glGetUniformLocation(m_RendererID, name.c_str());

		if (location == -1)
		{
			HE_WARN("Shader: Uniform {0} no encontrado", name);
		}

		m_UniformLocationCache[name] = location;
		return location;
	}

	std::string Shader::ReadFile(const std::string& filePath)
	{
		
		std::string shaderReaded = "";

		std::ifstream shaderFile(filePath, std::ios::in | std::ios::binary);

		//si no se pudo abrir el archivo, no debemos continuar
		if (!shaderFile) 
		{
			HE_ERROR("Shader: No se pudo abrir el archivo de shader {0}", filePath);
			return shaderReaded;
		}

		//leemos el contenido del archivo
		shaderFile.seekg(0, std::ios::end); //movemos el cursor al final del archivo
		auto fileSize = shaderFile.tellg(); //obtenemos el tamaño del archivo

		// si el tamaño es 0, no se puedo leer el archivo
		if (fileSize == std::streampos(-1)) 
		{
			HE_ERROR("Shader: No se pudo leer el archivo de shader {0}", filePath);
			return shaderReaded;
		}

		if (fileSize == 0) 
		{
			HE_WARN("Shader: El archivo de shader {0} esta vacio", filePath);
			return shaderReaded;
		}

		shaderReaded.resize(static_cast<size_t>(fileSize));//cambiamos el tamaño del string para que sea igual al tamaño del archivo
		shaderFile.seekg(0, std::ios::beg); //movemos el cursor al inicio del archivo para poder leerlo
		shaderFile.read(&shaderReaded[0], fileSize); //leemos el contenido del archivo

		return shaderReaded;
	}

	unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
	{
		return 0;
	}

	unsigned int Shader::CreateProgram(const std::string& vertexSource, const std::string& fragmentSource)
	{
		return 0;
	}

	void Shader::SetInt(const std::string& name, int value)
	{
		glUniform1i(GetUniformLocation(name), value);
	}

	void Shader::SetFloat(const std::string& name, float value)
	{
		glUniform1f(GetUniformLocation(name), value);
	}

	void Shader::SetVec2(const std::string& name, const glm::vec2& value)
	{
		glUniform2fv(GetUniformLocation(name), 1, &value[0]);
	}

	void Shader::SetVec3(const std::string& name, const glm::vec3& value)
	{
		glUniform3fv(GetUniformLocation(name), 1, &value[0]);
	}

	void Shader::SetVec4(const std::string& name, const glm::vec4& value)
	{
		glUniform4fv(GetUniformLocation(name), 1, &value[0]);
	}	

	void Shader::SetMat4(const std::string& name, const glm::mat4& matrix)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
	}

}








