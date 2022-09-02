#include "GradientImageScene.h"
#include <SDL.h>


void GradientImageScene::OnInit()
{
	gradientImage = imageFactory.MakeGradientImage(GetApp());
}

void GradientImageScene::OnRender()
{
	SDL_RenderCopy(GetApp().get().Renderer(), gradientImage->GetTexture(), nullptr, nullptr);
}
