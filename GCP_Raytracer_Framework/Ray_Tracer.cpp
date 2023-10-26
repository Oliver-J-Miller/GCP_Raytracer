#include "Ray_Tracer.h"

RayTracer::RayTracer()
{
	Sphere *s = new Sphere(glm::vec3(320, 240, -50), 50.0f,glm::vec3(0.f, 0.f, 1.0f));
	Sphere* s2 = new Sphere(glm::vec3(150, 100, -20), 40.0f, glm::vec3(0.f, 1.0f, 0.0f));
	objects.push_back(s);
	objects.push_back(s2);
}

RayTracer::~RayTracer()
{
}

glm::vec3 RayTracer::TraceRay(Ray _ray)
{
	RayInfo rF;
	for (int count = 0; count < objects.size(); count++)
	{
		rF = objects[count]->RayIntersect(_ray);

		if (rF.intersect == true)
		{
			return objects[count]->Shade(rF.iP);
		}
	}
	return glm::vec3(0.1, 0.0, 0.0);
}

