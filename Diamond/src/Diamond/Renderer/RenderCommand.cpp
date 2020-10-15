#include "dipch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Diamond {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}