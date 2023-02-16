cmake_minimum_required(VERSION 3.20)

project(indie_studio)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(raylib REQUIRED)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_BUILD_TYPE Debug)

if(MSVC)
  add_compile_options(/Wv:17)
endif()

#add_link_options(-fsanitize=address)

file(GLOB sources
  src/asset_manager/asset_manager.cpp
  src/collision_manager/collision_manager.cpp
  src/game_objects/game/block_obj.cpp
  src/game_objects/game/brick_obj.cpp
  src/game_objects/game/game_object.cpp
  src/game_objects/game/ground_obj.cpp
  src/game_objects/game/bomb.cpp
  src/game_objects/game/flame.cpp
  src/game_objects/game/pnj_manager.cpp
  src/game_objects/game/wall_obj.cpp
  src/game_objects/game/power_ups/bomb_up.cpp
  src/game_objects/game/power_ups/fire_up.cpp
  src/game_objects/game/power_ups/power_ups.cpp
  src/game_objects/game/power_ups/speed_up.cpp
  src/game_objects/game/power_ups/wall_pass.cpp
  src/game_objects/menu/general_settings.cpp
  src/game_objects/menu/how_to_play.cpp
  src/game_objects/menu/main_menu.cpp
  src/game_objects/menu/pause_game.cpp
  src/game_objects/menu/pre_game_settings.cpp
  src/game_objects/menu/font_game.cpp
  src/raylib/ModelAnimation.cpp
  src/raylib/Ray.cpp
  src/raylib/audiostream.cpp
  src/raylib/boundingbox.cpp
  src/raylib/camera.cpp
  src/raylib/color.cpp
  src/raylib/engine.cpp
  src/raylib/font.cpp
  src/raylib/glyph_info.cpp
  src/raylib/image.cpp
  src/raylib/material.cpp
  src/raylib/materialmap.cpp
  src/raylib/model.cpp
  src/raylib/music.cpp
  src/raylib/raycollision.cpp
  src/raylib/rectangle.cpp
  src/raylib/render_texture.cpp
  src/raylib/shader.cpp
  src/raylib/sound.cpp
  src/raylib/texture.cpp
  src/raylib/vector2.cpp
  src/raylib/vector3.cpp
  src/raylib/vector4.cpp
  src/raylib/wave.cpp
  src/raylib/mesh.cpp
  src/background_manager/background_manager.cpp
  src/components/animation.cpp
  src/components/button.cpp
  src/components/hit_box.cpp
  src/components/power_up.cpp
  src/components/speed.cpp
  src/event_manager/event_manager.cpp
  src/main.cpp
  src/sound_manager/sound_manager.cpp
 )

add_executable(bomberman ${sources})

target_include_directories(bomberman PUBLIC
  "./include"
  "./include/assets_manager"
  "./include/event_manager"
  "./include/game_object"
  "./include/components"
  "./include/game_object/game"
  "./include/game_object/game/power_ups_obj"
  "./include/game_object/menu"
  "./include/collision_manager"
  "./include/sound_manager"
  "./include/objects"
  "./include/background_manager")

target_link_libraries(bomberman raylib)

