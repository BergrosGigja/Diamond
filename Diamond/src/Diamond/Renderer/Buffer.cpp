#include "dipch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Diamond {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::OpenGL:
				return new OpenGLVertexBuffer(vertices, size);
			case RendererAPI::API::None:
			default:
				DI_CORE_TRACE(false, "Unknown RendererAPI!");
				return nullptr;
		}
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::OpenGL:
				return new OpenGLIndexBuffer(indices, size);
			case RendererAPI::API::None:
			default:
				DI_CORE_TRACE(false, "Unknown RendererAPI!");
				return nullptr;
		}
	}
}