#include "scene.h"

#include <GL/glut.h>
#include <stdio.h> 
#include "SOIL/SOIL.h"  
#define TRUE 1 
#define FALSE 0  
#define INVALID_VERTEX_INDEX 0
#include "GL/glut.h"

#include <obj/load.h>
#include <obj/draw.h>

double rotate;
double a = 0;
double s_rotate = -55;
double b = 0;



void sun_rotate(double b)
{
	
	if(s_rotate < -110)
	{
		b = 0;
		s_rotate = -110;
	}
	else if(s_rotate > 0)
	{
		b = 0;
		s_rotate = 0;
	}
	s_rotate += b;
}

void door_rotate(double time)
{
	if(rotate < -95)
	{
		a = 0;
		rotate = -95;
	}
	else if(rotate > 0)
	{
		a = 0;
		rotate = 0;
	}
	rotate += time*a;
}

void init_scene(Scene* scene)
{
    load_model(&(scene->walls_model), "models/walls.obj");
    scene->walls_texture_id = load_texture("textures/wall.png");
	
	load_model(&(scene->floor_model), "models/floor.obj");
    scene->floor_texture_id = load_texture("textures/floor.png");

	load_model(&(scene->roof_model), "models/roof.obj");	
    scene->roof_texture_id = load_texture("textures/roof.png");
	
	load_model(&(scene->wires_model), "models/wires.obj");	
    scene->wires_texture_id = load_texture("textures/wires.png");
	
	load_model(&(scene->door_model), "models/door.obj");
    scene->door_texture_id = load_texture("textures/door.png");
	
	load_model(&(scene->grass_model), "models/grass.obj");
    scene->grass_texture_id = load_texture("textures/grass.jpg");
	
	load_model(&(scene->sky_model), "models/sky.obj");
    scene->sky_texture_id = load_texture("textures/sky.png");
	
	load_model(&(scene->sun_model), "models/sun.obj");
    scene->sun_texture_id = load_texture("textures/sun.png");
	
	scene->help_texture_id = load_texture("textures/help.png");

    scene->material.ambient.red = 0.2;
    scene->material.ambient.green = 0.2;
    scene->material.ambient.blue = 0.2;

    scene->material.diffuse.red = 1;
    scene->material.diffuse.green = 1;
    scene->material.diffuse.blue = 1;

    scene->material.specular.red = 0.3;
    scene->material.specular.green = 0.3;
    scene->material.specular.blue = 0.3;

    scene->material.shininess = 10;
	
	set_lighting();
}


void set_lighting()
{
    float ambient_light[] = { 2.5f, 2.5f, 2.5f, 3.0f };
    float diffuse_light[] = { 2.5f, 2.5f, 2.5, 3.0f };
    float specular_light[] = { 5.0f, 5.0f, 5.0f, 5.0f };
    float position[] = { 70.0f, 20.0f, 80.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void draw_scene(const Scene* scene)
{
	glEnable(GL_TEXTURE_2D);
	
	glPushMatrix();
    set_material(&(scene->material));
	glPopMatrix();
	
    glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->walls_texture_id);
    draw_model(&(scene->walls_model));
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->roof_texture_id);
    draw_model(&(scene->roof_model));
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->floor_texture_id);
	draw_model(&(scene->floor_model));
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->wires_texture_id);
	draw_model(&(scene->wires_model));
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->grass_texture_id);
	draw_model(&(scene->grass_model));
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->sky_texture_id);
	draw_model(&(scene->sky_model));
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->door_texture_id);
	glTranslatef(-0.85, 0, -0.5);
    glRotatef(0+rotate,0,0,1);
	draw_model(&(scene->door_model));
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->sun_texture_id);
    glRotatef(0+s_rotate,1,0,0);
	draw_model(&(scene->sun_model));
	glPopMatrix();
	
	
	glBindTexture(GL_TEXTURE_2D, scene->help_texture_id);
	
	glEnd();
}

void set_door_rotate(int x)
{
	a = x;
}