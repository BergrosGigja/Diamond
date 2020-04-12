#pragma once

#include "Diamond/Layer.h"

#include "Diamond/Events/ApplicationEvent.h"
#include "Diamond/Events/KeyEvent.h"
#include "Diamond/Events/MouseEvent.h"

namespace Diamond {

	class DIAMOND_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}
