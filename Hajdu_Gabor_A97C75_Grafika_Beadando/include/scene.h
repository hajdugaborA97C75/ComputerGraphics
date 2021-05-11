#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Model walls_model;
	Model floor_model;
	Model rudak_model;
	Model chest_bottom_model;
	Model chest_top_model;
	Model ceiling_model;
    Material material;
    GLuint walls_texture_id;
	GLuint floor_texture_id;
	GLuint rudak_texture_id;
	GLuint help_texture_id;
	GLuint chest_texture_id;
	GLuint ceiling_texture_id;
	GLuint map_texture_id;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

void columnmove(double time);

#endif /* SCENE_H */
