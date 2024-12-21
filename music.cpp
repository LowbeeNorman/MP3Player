#include "music.h"

Music::Music() {
    BASS_Init(-1, 44100, 0, 0, NULL);

}
