// generated from users/bajackal -*- buffer-read-only: t -*-

#pragma once

#if defined(COMBO_ENABLE)
#    define COMBO_COUNT 4
#endif  // !COMBO_ENABLE

#define LAYOUT_banjackal(\
     K00, K01, K02, K03, K04, K05,      K06, K07, K08, K09, K10, K11,\
     K12, K13, K14, K15, K16, K17,      K18, K19, K20, K21, K22, K23,\
     K24, K25, K26, K27, K28, K29,      K30, K31, K32, K33, K34, K35,\
     N36, N37, N38, K39, K40, K41,      K42, K43, K44, N45, N46, N47\
)\
LAYOUT_split_3x6_3(\
K00, K01, K02, K03, K04, K05,      K06, K07, K08, K09, K10, K11,\
K12, K13, K14, K15, K16, K17,      K18, K19, K20, K21, K22, K23,\
K24, K25, K26, K27, K28, K29,      K30, K31, K32, K33, K34, K35,\
               K39, K40, K41,      K42, K43, K44\
)
