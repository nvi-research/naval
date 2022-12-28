#pragma once

#define NAVAL_EXPAND(x) x
#define NAVAL_GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16,     \
                        _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, \
                        _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, \
                        _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, \
                        _62, _63, _64, NAME, ...)                                                  \
  NAME
#define NAVAL_PASTE(...)                                                                        \
  NAVAL_EXPAND(NAVAL_GET_MACRO(                                                                 \
      __VA_ARGS__, NAVAL_PASTE64, NAVAL_PASTE63, NAVAL_PASTE62, NAVAL_PASTE61, NAVAL_PASTE60,   \
      NAVAL_PASTE59, NAVAL_PASTE58, NAVAL_PASTE57, NAVAL_PASTE56, NAVAL_PASTE55, NAVAL_PASTE54, \
      NAVAL_PASTE53, NAVAL_PASTE52, NAVAL_PASTE51, NAVAL_PASTE50, NAVAL_PASTE49, NAVAL_PASTE48, \
      NAVAL_PASTE47, NAVAL_PASTE46, NAVAL_PASTE45, NAVAL_PASTE44, NAVAL_PASTE43, NAVAL_PASTE42, \
      NAVAL_PASTE41, NAVAL_PASTE40, NAVAL_PASTE39, NAVAL_PASTE38, NAVAL_PASTE37, NAVAL_PASTE36, \
      NAVAL_PASTE35, NAVAL_PASTE34, NAVAL_PASTE33, NAVAL_PASTE32, NAVAL_PASTE31, NAVAL_PASTE30, \
      NAVAL_PASTE29, NAVAL_PASTE28, NAVAL_PASTE27, NAVAL_PASTE26, NAVAL_PASTE25, NAVAL_PASTE24, \
      NAVAL_PASTE23, NAVAL_PASTE22, NAVAL_PASTE21, NAVAL_PASTE20, NAVAL_PASTE19, NAVAL_PASTE18, \
      NAVAL_PASTE17, NAVAL_PASTE16, NAVAL_PASTE15, NAVAL_PASTE14, NAVAL_PASTE13, NAVAL_PASTE12, \
      NAVAL_PASTE11, NAVAL_PASTE10, NAVAL_PASTE9, NAVAL_PASTE8, NAVAL_PASTE7, NAVAL_PASTE6,     \
      NAVAL_PASTE5, NAVAL_PASTE4, NAVAL_PASTE3, NAVAL_PASTE2, NAVAL_PASTE1)(__VA_ARGS__))
#define NAVAL_PASTE2(func, v1) func(v1)
#define NAVAL_PASTE3(func, v1, v2) NAVAL_PASTE2(func, v1) NAVAL_PASTE2(func, v2)
#define NAVAL_PASTE4(func, v1, v2, v3) NAVAL_PASTE2(func, v1) NAVAL_PASTE3(func, v2, v3)
#define NAVAL_PASTE5(func, v1, v2, v3, v4) NAVAL_PASTE2(func, v1) NAVAL_PASTE4(func, v2, v3, v4)
#define NAVAL_PASTE6(func, v1, v2, v3, v4, v5) \
  NAVAL_PASTE2(func, v1) NAVAL_PASTE5(func, v2, v3, v4, v5)
#define NAVAL_PASTE7(func, v1, v2, v3, v4, v5, v6) \
  NAVAL_PASTE2(func, v1) NAVAL_PASTE6(func, v2, v3, v4, v5, v6)
#define NAVAL_PASTE8(func, v1, v2, v3, v4, v5, v6, v7) \
  NAVAL_PASTE2(func, v1) NAVAL_PASTE7(func, v2, v3, v4, v5, v6, v7)
#define NAVAL_PASTE9(func, v1, v2, v3, v4, v5, v6, v7, v8) \
  NAVAL_PASTE2(func, v1) NAVAL_PASTE8(func, v2, v3, v4, v5, v6, v7, v8)
#define NAVAL_PASTE10(func, v1, v2, v3, v4, v5, v6, v7, v8, v9) \
  NAVAL_PASTE2(func, v1) NAVAL_PASTE9(func, v2, v3, v4, v5, v6, v7, v8, v9)
#define NAVAL_PASTE11(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) \
  NAVAL_PASTE2(func, v1) NAVAL_PASTE10(func, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#define NAVAL_PASTE12(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) \
  NAVAL_PASTE2(func, v1)                                                  \
  NAVAL_PASTE11(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#define NAVAL_PASTE13(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) \
  NAVAL_PASTE2(func, v1)                                                       \
  NAVAL_PASTE12(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#define NAVAL_PASTE14(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) \
  NAVAL_PASTE2(func, v1)                                                            \
  NAVAL_PASTE13(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13)
#define NAVAL_PASTE15(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14) \
  NAVAL_PASTE2(func, v1)                                                                 \
  NAVAL_PASTE14(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14)
#define NAVAL_PASTE16(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) \
  NAVAL_PASTE2(func, v1)                                                                      \
  NAVAL_PASTE15(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#define NAVAL_PASTE17(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE16(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#define NAVAL_PASTE18(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17)                                                                         \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE17(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#define NAVAL_PASTE19(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18)                                                                    \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE18(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18)
#define NAVAL_PASTE20(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19)                                                               \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE19(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19)
#define NAVAL_PASTE21(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20)                                                          \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE20(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20)
#define NAVAL_PASTE22(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21)                                                     \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE21(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21)
#define NAVAL_PASTE23(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22)                                                \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE22(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22)
#define NAVAL_PASTE24(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23)                                           \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE23(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23)
#define NAVAL_PASTE25(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24)                                      \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE24(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24)
#define NAVAL_PASTE26(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25)                                 \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE25(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25)
#define NAVAL_PASTE27(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26)                            \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE26(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26)
#define NAVAL_PASTE28(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27)                       \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE27(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27)
#define NAVAL_PASTE29(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28)                  \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE28(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28)
#define NAVAL_PASTE30(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29)             \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE29(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29)
#define NAVAL_PASTE31(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30)        \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE30(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30)
#define NAVAL_PASTE32(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31)   \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE31(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31)
#define NAVAL_PASTE33(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32)                                                                         \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE32(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32)
#define NAVAL_PASTE34(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33)                                                                    \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE33(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33)
#define NAVAL_PASTE35(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34)                                                               \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE34(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34)
#define NAVAL_PASTE36(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35)                                                          \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE35(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35)
#define NAVAL_PASTE37(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36)                                                     \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE36(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36)
#define NAVAL_PASTE38(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37)                                                \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE37(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37)
#define NAVAL_PASTE39(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38)                                           \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE38(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38)
#define NAVAL_PASTE40(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39)                                      \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE39(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39)
#define NAVAL_PASTE41(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40)                                 \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE40(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40)
#define NAVAL_PASTE42(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41)                            \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE41(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41)
#define NAVAL_PASTE43(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42)                       \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE42(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42)
#define NAVAL_PASTE44(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43)                  \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE43(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43)
#define NAVAL_PASTE45(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44)             \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE44(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44)
#define NAVAL_PASTE46(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45)        \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE45(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45)
#define NAVAL_PASTE47(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46)   \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE46(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46)
#define NAVAL_PASTE48(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47)                                                                         \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE47(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47)
#define NAVAL_PASTE49(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47, v48)                                                                    \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE48(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48)
#define NAVAL_PASTE50(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47, v48, v49)                                                               \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE49(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49)
#define NAVAL_PASTE51(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47, v48, v49, v50)                                                          \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE50(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50)
#define NAVAL_PASTE52(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47, v48, v49, v50, v51)                                                     \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE51(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50,    \
                v51)
#define NAVAL_PASTE53(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47, v48, v49, v50, v51, v52)                                                \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE52(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50,    \
                v51, v52)
#define NAVAL_PASTE54(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47, v48, v49, v50, v51, v52, v53)                                           \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE53(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50,    \
                v51, v52, v53)
#define NAVAL_PASTE55(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47, v48, v49, v50, v51, v52, v53, v54)                                      \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE54(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50,    \
                v51, v52, v53, v54)
#define NAVAL_PASTE56(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47, v48, v49, v50, v51, v52, v53, v54, v55)                                 \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE55(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50,    \
                v51, v52, v53, v54, v55)
#define NAVAL_PASTE57(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47, v48, v49, v50, v51, v52, v53, v54, v55, v56)                            \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE56(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50,    \
                v51, v52, v53, v54, v55, v56)
#define NAVAL_PASTE58(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57)                       \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE57(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50,    \
                v51, v52, v53, v54, v55, v56, v57)
#define NAVAL_PASTE59(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58)                  \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE58(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50,    \
                v51, v52, v53, v54, v55, v56, v57, v58)
#define NAVAL_PASTE60(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59)             \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE59(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50,    \
                v51, v52, v53, v54, v55, v56, v57, v58, v59)
#define NAVAL_PASTE61(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60)        \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE60(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50,    \
                v51, v52, v53, v54, v55, v56, v57, v58, v59, v60)
#define NAVAL_PASTE62(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61)   \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE61(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50,    \
                v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61)
#define NAVAL_PASTE63(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61,   \
                      v62)                                                                         \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE62(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50,    \
                v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62)
#define NAVAL_PASTE64(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, \
                      v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31,   \
                      v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46,   \
                      v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61,   \
                      v62, v63)                                                                    \
  NAVAL_PASTE2(func, v1)                                                                           \
  NAVAL_PASTE63(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, \
                v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,    \
                v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50,    \
                v51, v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63)
