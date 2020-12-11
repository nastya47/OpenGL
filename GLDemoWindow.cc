/*
 * GLDemoWindow.cc
 *
 *  Created on: 7 –Ω–æ—è–±. 2020 –≥.
 *      Author: unyuu
 */

#include <cmath>
#include "GLDemoWindow.h"

#include "Primitives.h"

static constexpr double Pi = acos(-1.);

// Û·
static VertexVector s_cube_vertices {
	{  1.0,  1.0,  4.0 },
	{  1.0, -1.0,  4.0 },
	{ -3.0, -1.0,  4.0 },
	{ -3.0,  1.0,  4.0 },
	{  1.0,  1.0,  0.0 },
	{  1.0, -1.0,  0.0 },
	{ -3.0, -1.0,  0.0 },
	{ -3.0,  1.0,  0.0 },
};

static FaceVector s_cube_faces {
	{ 4, 0, 1, 2, 3 },
	{ 4, 7, 6, 5, 4 },
	{ 4, 1, 0, 4, 5 },
	{ 4, 3, 2, 6, 7 },
	{ 4, 0, 3, 7, 4 },
	{ 4, 2, 1, 5, 6 },
};

static NormalVector s_cube_normals {
	{  0.0,  0.0,  1.0 },
	{  0.0,  0.0, -1.0 },
	{  1.0,  0.0,  0.0 },
	{ -1.0,  0.0,  0.0 },
	{  0.0,  1.0,  0.0 },
	{  0.0, -1.0,  0.0 },
};

static ColorVector s_cube_colors {
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
};

static TexCoordVector s_cube_tex_coords {
	{ { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 } },
	{ { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 } },
	{ { 0.50, 0.00 }, { 1.00, 0.00 }, { 1.00, 0.50 }, { 0.50, 0.50 } },
	{ { 0.50, 0.00 }, { 1.00, 0.00 }, { 1.00, 0.50 }, { 0.50, 0.50 } },
	{ { 0.00, 0.50 }, { 1.00, 0.50 }, { 1.00, 1.00 }, { 0.00, 1.00 } },
	{ { 0.00, 0.50 }, { 1.00, 0.50 }, { 1.00, 1.00 }, { 0.00, 1.00 } },
};

// ˚¯‡
static VertexVector s_roof_vertices {
	{  1.0,  -1.2,  4.0 },
	{  1.0,   1.2,  4.0 },
	{ -3.0,   1.2,  4.0 },
	{ -3.0,  -1.2,  4.0 },
	{  1.0,   0.0,  4.5 },
	{ -3.0,   0.0,  4.5 },
};

static FaceVector s_roof_faces {
	{ 4, 0, 1, 2, 3 },
	{ 4, 1, 4, 5, 2 },
	{ 4, 0, 3, 5, 4 },
	{ 3, 0, 4, 1 },
	{ 3, 2, 5, 3 },
};

static NormalVector s_roof_normals {
	{  0.0,  0.0, -1.0 },
	{  0.0,  1.0,  1.0 },
	{  0.0, -1.0,  1.0 },
	{  1.0,  0.0,  0.0 },
	{ -1.0,  0.0,  0.0 },
};

static ColorVector s_roof_colors {
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
};

static TexCoordVector s_roof_tex_coords {
	{ { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 } },
	{ { 0.00, 0.50 }, { 0.00, 0.00 }, { 0.50, 0.00 }, { 0.50, 0.50 } },
	{ { 0.50, 0.50 }, { 0.00, 0.50 }, { 0.00, 0.00 }, { 0.50, 0.00 } },
	{ { 0.50, 1.00 }, { 0.75, 0.75 }, { 1.00, 1.00 } },
	{ { 0.50, 1.00 }, { 0.75, 0.75 }, { 1.00, 1.00 } },
};

//“Û·‡
static VertexVector s_tube_vertices {
	{ -0.25, -0.25, 5.0 },
	{ -0.25, -0.5,  5.0 },
	{ -0.5,  -0.5,  5.0 },
	{ -0.5,  -0.25, 5.0 },
	{ -0.25, -0.25, 4.0 },
	{ -0.25, -0.5,  4.0 },
	{ -0.5,  -0.5,  4.0 },
	{ -0.5,  -0.25, 4.0 },
};

static FaceVector s_tube_faces {
	{ 4, 0, 1, 2, 3 },
	{ 4, 7, 6, 5, 4 },
	{ 4, 1, 0, 4, 5 },
	{ 4, 3, 2, 6, 7 },
	{ 4, 0, 3, 7, 4 },
	{ 4, 2, 1, 5, 6 },
};

static NormalVector s_tube_normals {
	{  0.0,  0.0,  1.0 },
	{  0.0,  0.0, -1.0 },
	{  1.0,  0.0,  0.0 },
	{ -1.0,  0.0,  0.0 },
	{  0.0,  1.0,  0.0 },
	{  0.0, -1.0,  0.0 },
};

static ColorVector s_tube_colors {
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
	{  1.0f,  1.0f,  1.0f },
};

static TexCoordVector s_tube_tex_coords {
	{ { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 } },
	{ { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 }, { 0.00, 0.00 } },
	{ { 0.50, 0.50 }, { 0.75, 0.50 }, { 0.75, 1.00 }, { 0.50, 1.00 } },
	{ { 0.50, 0.50 }, { 0.75, 0.50 }, { 0.75, 1.00 }, { 0.50, 1.00 } },
	{ { 0.50, 0.50 }, { 0.75, 0.50 }, { 0.75, 1.00 }, { 0.50, 1.00 } },
	{ { 0.50, 0.50 }, { 0.75, 0.50 }, { 0.75, 1.00 }, { 0.50, 1.00 } },
};

Model cube { s_cube_vertices, s_cube_faces, s_cube_normals, s_cube_colors, s_cube_tex_coords };
Model crisha { s_roof_vertices, s_roof_faces, s_roof_normals, s_roof_colors, s_roof_tex_coords };
Model tube { s_tube_vertices, s_tube_faces, s_tube_normals, s_tube_colors, s_tube_tex_coords };

GLDemoWindow::GLDemoWindow(int width, int height) // @suppress("Class members should be properly initialized")
: Window(width, height),
  _home("home.png"), _roof("roof.png"),
  _green("green.png"), _brown("brown.png"), _orange("orange.png")
{
	SDL_GL_SetSwapInterval(1); // VSync
}

void GLDemoWindow::setup()
{
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE);

	glClearColor(0.2f, 0.35f, 0.45f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, double(width()) / double(height()), 0.1, 30.0);
	glMatrixMode(GL_MODELVIEW);
}

void GLDemoWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(10.0, 10.0, 10.0,
			  0.0, 0.0, 0.0,
			  0.0, 0.0, 1.0);


	glRotated(_angle, 0.0, 0.0, 1.0);

	_home.bind();
	glEnable(GL_TEXTURE_2D);
	draw_model(cube);
	glDisable(GL_TEXTURE_2D);

	_roof.bind();
	glEnable(GL_TEXTURE_2D);
	draw_model(crisha);
	glDisable(GL_TEXTURE_2D);

	_brown.bind();
	glEnable(GL_TEXTURE_2D);
	make_cylinder_smooth(32, 4.);
	glDisable(GL_TEXTURE_2D);

	_brown.bind();
	glEnable(GL_TEXTURE_2D);
	draw_model(tube);
	glDisable(GL_TEXTURE_2D);

	_green.bind();
	glEnable(GL_TEXTURE_2D);
	make_cone_smooth(32, 0., 4., 2, 1, 0.75);
	make_cone_smooth(32, 0., 4., 2.8, 1.8, 0.6);
	make_cone_smooth(32, 0., 4., 3.6, 2.6, 0.45);
	glDisable(GL_TEXTURE_2D);

	make_sphere_smooth(64, 32, -2, 4, 0.9, 0.9);
	make_sphere_smooth(64, 32, -2, 4, 2.4, 0.7);
	make_sphere_smooth(64, 32, -2, 4, 3.55, 0.5);

	_orange.bind();
	glEnable(GL_TEXTURE_2D);
	make_cone_flat(32, -2., 3.55, 5.0, 4.2, 0.1);
	glDisable(GL_TEXTURE_2D);
}

void GLDemoWindow::draw_model(Model &model)
{
	for (unsigned i = 0; i < model.faces.size(); ++i) {
		int count = model.faces[i][0];
		if (count == 3)
			glBegin(GL_TRIANGLES);
		else if (count == 4)
			glBegin(GL_QUADS);
		else
			glBegin(GL_POLYGON);

		glNormal3dv(&model.normals[i][0]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, &model.colors[i][0]);
		for (int j = 1; j <= count; ++j) {
			glTexCoord2dv(&model.tex_coords[i][j-1][0]);
			glVertex3dv(&model.vertices[model.faces[i][j]][0]);
		}

		glEnd();
	}
}

void GLDemoWindow::do_logic()
{
	_angle -= 0.5;
	if (_angle >= 360.)
		_angle -= 360.;
}



