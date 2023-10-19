#include "Ray_Tracer.h"

RayTracer::RayTracer()
{
	Sphere *s = new Sphere();
	objects.push_back(s);
}

RayTracer::~RayTracer()
{
}

glm::vec3 RayTracer::TraceRay(Ray _ray)
{
	RayInfo rF;

	rF = objects[0]->RayIntersect(_ray);

	if (rF.intersect == true)
	{
		return objects[0]->Shade(rF.iP);
	}
	return glm::vec3(0.0,0.0,0.0);
}

