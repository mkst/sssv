#ifndef MESSAGES_H
#define MESSAGES_H


#define COPY_MESSAGE(SRC, DST) \
while (*SRC != EOM) { \
  *DST++ = *SRC++; \
} \
*DST = EOM;


// lang 33 (level select menu)

#define MSG_ZONE_SELECT         0
#define MSG_BANK_SELECT         1
#define MSG_SECURED             2
#define MSG_AVAILABLE           3
#define MSG_SOUVENIR_COLLECTED  4
#define MSG_RECORD_1            5
#define MSG_RECORD_2            6
#define MSG_HIGH_SCORE          7
#define MSG_ROUNDS              8
#define MSG_SELECT              9
#define MSG_COPY                10
#define MSG_DELETE              11
#define MSG_COPY2               12
#define MSG_TO                  13
#define MSG_CANCEL              14
#define MSG_DELETE2             15
#define MSG_SECURE_ZONES        16
#define MSG_SPECIES             17
#define MSG_ENCOUNTERED         18
#define MSG_MISSION_BRIEF       19
#define MSG_OPTIONS             20
#define MSG_CONTINUE            21
#define MSG_MISSION_BRIEF2      22
#define MSG_RESTART_ZONE        23
#define MSG_CANCEL2             24
#define MSG_CONFIRM             25
#define MSG_REPLAY_ZONE         26
#define MSG_EXIT_ZONE           27
// somewhat meta, e.g. ENGLISH
#define MSG_LANGUAGE            28
#define MSG_POO_POO             29
#define MSG_LEAVE_SV            30

#define MSG_SELECT_A_BANK       214

// lang 34

#define MSG_DUMMY               13
#define MSG_PRESS_START         14
#define MSG_CONTROLLER_NOT_CONNECTED 16

#endif
