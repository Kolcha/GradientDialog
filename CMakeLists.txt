# SPDX-FileCopyrightText: 2020 Nick Korotysh <nick.korotysh@gmail.com>
#
# SPDX-License-Identifier: LGPL-3.0-or-later

cmake_minimum_required(VERSION 3.19)

project(GradientDialog VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_library(gradient_dialog STATIC
  gradient_dialog.cc
  gradient_dialog.h
  gradient_dialog.ui
  gradient_edit.cc
  gradient_edit.h
  gradient_stops_edit.cc
  gradient_stops_edit.h
)

target_link_libraries(gradient_dialog PUBLIC Qt6::Widgets)

target_include_directories(gradient_dialog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

qt_add_executable(gradient_dialog_demo gradient_dialog_demo.cc)
set_target_properties(gradient_dialog_demo PROPERTIES
  MACOSX_BUNDLE_GUI_IDENTIFIER com.github.kolcha.gradient-dialog-demo
  MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
  MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
  MACOSX_BUNDLE TRUE
  WIN32_EXECUTABLE TRUE
)
target_link_libraries(gradient_dialog_demo PRIVATE gradient_dialog Qt6::Widgets)
