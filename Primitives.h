/*
 * Primitives.h
 *
 *  Created on: 9 РЅРѕСЏР±. 2020 Рі.
 *      Author: unyuu
 */

#ifndef PRIMITIVES_H_
#define PRIMITIVES_H_

#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>

// Р—Р°РґР°РЅРёРµ:
// 1) Р РµР°Р»РёР·РѕРІР°С‚СЊ РІСЃРµ РѕСЃС‚Р°Р»СЊРЅС‹Рµ С„СѓРЅРєС†РёРё
// 2) Р”РѕР±Р°РІРёС‚СЊ РіРµРЅРµСЂР°С†РёСЋ С‚РµРєСЃС‚СѓСЂРЅС‹С… РєРѕРѕСЂРґРёРЅР°С‚
// 3) РќР°СЂРёСЃРѕРІР°С‚СЊ СЃРЅРµРіРѕРІРёРєР° Рё С‘Р»РѕС‡РєСѓ РІРѕР·Р»Рµ РґРѕРјРёРєР° :)



// Р�Р· РґРµРєР°СЂС‚РѕРІРѕР№ РІ С†РёР»РёРЅРґСЂРёС‡РµСЃРєСѓСЋ
void cart2cyl(
		double x, double y, double z,
		double &r, double &phi, double &cz);
// Р�Р· С†РёР»РёРЅРґСЂРёС‡РµСЃРєРѕР№ РІ РґРµРєР°СЂС‚РѕРІСѓ
void cyl2cart(
		double r, double phi, double cz,
		double &x, double &y, double &z,
		double coord);

// Р�Р· РґРµРєР°СЂС‚РѕРІРѕР№ РІ СЃС„РµСЂРёС‡РµСЃРєСѓСЋ
void cart2sph(
		double x, double y, double z,
		double &r, double &phi, double &theta);
// Р�Р· СЃС„РµСЂРёС‡РµСЃРєРѕР№ РІ РґРµРєР°СЂС‚РѕРІСѓ
void sph2cart(
		double r, double phi, double theta,
		double &x, double &y, double &z,
		double coord);



void make_cylinder_flat(int sides); // РЅР° СЃР°РјРѕРј РґРµР»Рµ СЌС‚Рѕ РїСЂРёР·РјР°
void make_cylinder_smooth(int sides, double coord);
void make_cone_flat(int sides, double cdx, double cdy, double cdzUP, double cdzDOWN, double cdW); // РЅР° СЃР°РјРѕРј РґРµР»Рµ СЌС‚Рѕ РїРёСЂР°РјРёРґР°, С‚РѕР»СЊРєРѕ С‚СЃСЃСЃСЃСЃ~~~
void make_cone_smooth(int sides, double cdx, double cdy, double cdzUP, double cdzDOWN, double cdW);
void make_sphere_flat(int rows, int cols); // СЃС„РµСЂР° РЅР° РѕСЃРЅРѕРІРµ РіР»РѕР±СѓСЃР°
void make_sphere_smooth(int rows, int cols, double cdx, double cdy, double cdz, double cdr);
void make_icosphere_flat(int rows, int cols); // СЃС„РµСЂР° РЅР° РѕСЃРЅРѕРІРµ РёРєРѕСЃР°СЌРґСЂР°
void make_icosphere_smooth(int rows, int cols);


#endif /* PRIMITIVES_H_ */
