#pragma once

#include "Diamond/Core.h"
#include "Layer.h"

#include <vector>

namespace Diamond
{
	//wrapper over vector of layers
	//vector because we need to iterate through them all and in reverse
	//(not actual stack because of the need to push in middle of it, see overlays)
	//Layers are owned by the layerstack
	class DIAMOND_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};
}