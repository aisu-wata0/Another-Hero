// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <map>
#include <iostream>
#include <cassert>

#include <ctgmath>
#include <list>

#include "another_hero.h"
#include "stats.h"
#include "character.h"
#include "start.h"
#include "world.h"
#include "encounter.h"

#define kMovementRate 192.0f
#define kWindowWidth 1280
#define kWindowHeight 720
#define kBoardSize 9
#define kTileSizef kWindowHeight/kBoardSize
