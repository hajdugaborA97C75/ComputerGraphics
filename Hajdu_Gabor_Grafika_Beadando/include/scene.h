#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Model walls_model;
	Model floor_model;
	Model roof_model;
	Model door_model;
	Model wires_model;
	Model grass_model;
	Model sky_model;
	Model sun_model;
    Material material;
    GLuint walls_texture_id;
	GLuint floor_texture_id;
	GLuint roof_texture_id;
	GLuint help_texture_id;
	GLuint door_texture_id;
	GLuint wires_texture_id;
	GLuint grass_texture_id;
	GLuint sky_texture_id;
	GLuint sun_texture_id;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**S
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

void door_rotate(double time);

void sun_rotate(double time);

#endif /* SCENE_H */
