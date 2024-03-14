# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/eg0822/esp/esp-idf/components/bootloader/subproject"
  "/Users/eg0822/Documents/Repos/UABC/AsignaturasActuales/SistemasEmbebidos/PracticasLaboratorio/P3/build/bootloader"
  "/Users/eg0822/Documents/Repos/UABC/AsignaturasActuales/SistemasEmbebidos/PracticasLaboratorio/P3/build/bootloader-prefix"
  "/Users/eg0822/Documents/Repos/UABC/AsignaturasActuales/SistemasEmbebidos/PracticasLaboratorio/P3/build/bootloader-prefix/tmp"
  "/Users/eg0822/Documents/Repos/UABC/AsignaturasActuales/SistemasEmbebidos/PracticasLaboratorio/P3/build/bootloader-prefix/src/bootloader-stamp"
  "/Users/eg0822/Documents/Repos/UABC/AsignaturasActuales/SistemasEmbebidos/PracticasLaboratorio/P3/build/bootloader-prefix/src"
  "/Users/eg0822/Documents/Repos/UABC/AsignaturasActuales/SistemasEmbebidos/PracticasLaboratorio/P3/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/eg0822/Documents/Repos/UABC/AsignaturasActuales/SistemasEmbebidos/PracticasLaboratorio/P3/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/eg0822/Documents/Repos/UABC/AsignaturasActuales/SistemasEmbebidos/PracticasLaboratorio/P3/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
