#include "..\Headers\Container.h"

Container::Container(unsigned int gl_program_shader, glm::vec4 mapSize, unsigned int texture)
{
	_glProgramShader = gl_program_shader;
	_mapSize = mapSize;
	_texture = texture;
	Create();
}

void Container::Create()
{
	std::vector<VertexTextureFormat>verts;
	std::vector<glm::uvec3>indx;

	////////////////////// Up ////////////////////////
	
	indx.push_back(glm::uvec3(0, 1, 2));
verts.push_back(VertexTextureFormat(_mapSize.x, 0, _mapSize.w, 0, 0));
	verts.push_back(VertexTextureFormat(_mapSize.y, 0, _mapSize.w, 1, 0));
	verts.push_back(VertexTextureFormat(_mapSize.y, 0, _mapSize.z, 1, 1));
	verts.push_back(VertexTextureFormat(_mapSize.x, 0, _mapSize.z, 0, 1));
	indx.push_back(glm::uvec3(2, 3, 0));

	//vao
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	//vbo
	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexTextureFormat) * verts.size(), &verts[0], GL_STATIC_DRAW);

	//ibo
	glGenBuffers(1, &_ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indx.size() * 3, &indx[0], GL_STATIC_DRAW);

	// legatura intre atributele vertecsilor si pipeline, datele noastre sunt INTERLEAVED.
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexTextureFormat), (void*)0);						// trimite pozitii pe pipe 0
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexTextureFormat), (void*)(sizeof(float) * 3));		// trimite normale pe pipe 1
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexTextureFormat), (void*)(2 * sizeof(float) * 3));	// trimite texcoord pe pipe 2

	_numIndices = (unsigned int)indx.size() * 3;
}

void Container::Draw(glm::mat4 matView, glm::mat4 matProjection)
{
	glActiveTexture(GL_TEXTURE0 + 1);
	glBindTexture(GL_TEXTURE_2D, _texture);

	glUniform1i(glGetUniformLocation(_glProgramShader, "textura"), 1);

	glBindVertexArray(_vao);
	glUniformMatrix4fv(glGetUniformLocation(_glProgramShader, "model_matrix"), 1, false, glm::value_ptr(_modelMatrix));
	glDrawElements(GL_TRIANGLES, _numIndices, GL_UNSIGNED_INT, nullptr);
}