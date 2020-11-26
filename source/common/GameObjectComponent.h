#pragma once
#include "GameObject.h"

namespace our
{
	class GameObjectComponent
	{
	protected:

	public:
		bool Enabled;
		GameObject gameObject;

		GameObjectComponent()
		{

		}

		virtual void Start() //Called once per component
		{

		}

		virtual void Update(double deltaTime)  //Called every frame
		{

		}

		virtual void Draw()  //Called every frame after "Update()" execution
		{

		}

		virtual void Destroy()
		{

		}

		~GameObjectComponent()
		{

		}

		/*virtual GameObjectComponent DeepCopy(GameObject Clone)
		{
			return this() as GameObjectComponent;
		}*/
	};
}