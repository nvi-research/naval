if(USE_SANITIZER)
  include(sanitizers.cmake)
endif()

if(USE_STATIC_ANALYZER)
  if("clang-tidy" IN_LIST USE_STATIC_ANALYZER)
    set(CLANG_TIDY
        ON
        CACHE INTERNAL ""
    )
  else()
    set(CLANG_TIDY
        OFF
        CACHE INTERNAL ""
    )
  endif()
  if("iwyu" IN_LIST USE_STATIC_ANALYZER)
    set(IWYU
        ON
        CACHE INTERNAL ""
    )
  else()
    set(IWYU
        OFF
        CACHE INTERNAL ""
    )
  endif()
  if("cppcheck" IN_LIST USE_STATIC_ANALYZER)
    set(CPPCHECK
        ON
        CACHE INTERNAL ""
    )
  else()
    set(CPPCHECK
        OFF
        CACHE INTERNAL ""
    )
  endif()

  include(cmake/tools.cmake)

  clang_tidy(${CLANG_TIDY_ARGS})
  include_what_you_use(${IWYU_ARGS})
  cppcheck(${CPPCHECK_ARGS})
endif()
