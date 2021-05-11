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

double move;
double a = 0;



void columnmove(double time)
{
	move += time*a;	
}

void init_scene(Scene* scene)
{
    load_model(&(scene->walls_model), "models/folyoso.obj");
    scene->walls_texture_id = load_texture("textures/walls.png");
	
	load_model(&(scene->floor_model), "models/padlo.obj");
    scene->floor_texture_id = load_texture("textures/floor.png");

load_model(&(scene->ceiling_model), "models/teto.obj");
    scene->ceiling_texture_id = load_texture("textures/floor.png");


load_model(&(scene->rudak_model), "models/rudak.obj");
    scene->rudak_texture_id = load_texture("textures/rudak.png");
	
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
    float ambient_light[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    float diffuse_light[] = { 0.5f, 0.5f, 0.5, 1.0f };
    float specular_light[] = { 3.0f, 3.0f, 3.0f, 3.0f };
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
	draw_origin();
	glPopMatrix();
	
        glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->walls_texture_id);
        draw_model(&(scene->walls_model));
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->floor_texture_id);
	draw_model(&(scene->floor_model));
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->ceiling_texture_id);
	draw_model(&(scene->ceiling_model));
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->rudak_texture_id);
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(move, 0.0, 2.0, 0.0);
	draw_model(&(scene->rudak_model));
	glPopMatrix();
	
	glBindTexture(GL_TEXTURE_2D, scene->help_texture_id);
	
	glEnd();
}


void set_columnmove(int x)
{
	a = x;

}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
