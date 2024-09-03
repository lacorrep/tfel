message(STATUS "looked for castem library.")

if(CASTEM_INSTALL_PATH)
  set(CASTEMHOME "${CASTEM_INSTALL_PATH}")
else(CASTEM_INSTALL_PATH)
  set(CASTEMHOME $ENV{CASTEMHOME})
endif(CASTEM_INSTALL_PATH)

if(enable-castem-pleiades AND (NOT UNIX))
  message(FATAL "castem pleiades may only be used on linux")
endif(enable-castem-pleiades AND (NOT UNIX))

if(CASTEMHOME)
    find_path(CASTEM_INCLUDE_DIR castem.h
      HINTS ${CASTEMHOME}/include/c)
    if(CASTEM_INCLUDE_DIR STREQUAL "CASTEM_INCLUDE_DIR-NOTFOUND")
      find_path(CASTEM_INCLUDE_DIR castem.h
	HINTS ${CASTEMHOME}/include)
    endif(CASTEM_INCLUDE_DIR STREQUAL "CASTEM_INCLUDE_DIR-NOTFOUND")
    if(CASTEM_INCLUDE_DIR STREQUAL "CASTEM_INCLUDE_DIR-NOTFOUND")
      message(FATAL_ERROR "castem.h not found")
    endif(CASTEM_INCLUDE_DIR STREQUAL "CASTEM_INCLUDE_DIR-NOTFOUND")
    message(STATUS "Cast3M include files path detected: [${CASTEM_INCLUDE_DIR}].")
    set(CASTEM_ROOT "${CASTEMHOME}")
    tfel_add_c_cxx_definitions("CASTEM_ROOT=\"${CASTEMHOME}\"")
    tfel_add_c_cxx_definitions("HAVE_CASTEM=1")
    if(enable-castem-pleiades)
      set(castem_supported_versions 10 12 14 15 16 17 18)
      foreach(cversion ${castem_supported_versions})
	file(GLOB castem20${cversion}s "${CASTEMHOME}/bin/castem*${cversion}*_PLEIADES")
	foreach(cexe ${castem20${cversion}s})
	  if(castem_exe)
	    if(NOT (${castem_exe} STREQUAL ${cexe}))
	      message(FATAL "multiple castem executable found")
	    endif(NOT (${castem_exe} STREQUAL ${cexe}))
	  endif(castem_exe)
	  set(castem_exe     ${cexe})
	  set(castem_version ${cversion})
	endforeach(cexe ${castem20${cversion}s})
      endforeach(cversion ${castem_supported_versions})
    else(enable-castem-pleiades)
      set(castem_supported_versions 15 16 17 18)
      foreach(cversion ${castem_supported_versions})
	file(GLOB castem${cversion}s "${CASTEMHOME}/bin/castem${cversion}*")
	foreach(cexe ${castem${cversion}s})
	  if(castem_exe)
	    if(NOT (${castem_exe} STREQUAL ${cexe}))
	      message(FATAL "multiple castem executable found")
	    endif(NOT (${castem_exe} STREQUAL ${cexe}))
	  endif(castem_exe)
	  set(castem_exe     ${cexe})
	  set(castem_version ${cversion})
	endforeach(cexe ${castem${cversion}s})
      endforeach(cversion ${castem_supported_versions})
    endif(enable-castem-pleiades)
    if(castem_exe)
      message(STATUS "found castem executable ${castem_exe}")
    endif(castem_exe)
    set(HAVE_CASTEM ON)
else(CASTEMHOME)
  message(WARNING "no CASTEMHOME defined")
endif(CASTEMHOME)
