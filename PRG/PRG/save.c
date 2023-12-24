#include "main.h"

typedef struct Character Character;

uint32_t IntToBytesBigEndian(int i) {
    uint32_t* p = (uint32_t*)&i;
    uint32_t bytes = ((*p & 0xFF) << 24) | ((*p & 0xFF00) << 8) | ((*p & 0xFF0000) >> 8) | ((*p & 0xFF000000) >> 24);
    return bytes;
}

uint32_t FloatToBytesBigEndian(float f) {
    uint32_t* p = (uint32_t*)&f;
    uint32_t bytes = ((*p & 0xFF) << 24) | ((*p & 0xFF00) << 8) | ((*p & 0xFF0000) >> 8) | ((*p & 0xFF000000) >> 24);
    return bytes;
}

uint32_t rotr(uint32_t n, uint32_t d) {
    return (n >> d) | (n << (32 - d));
}

void Serialization(int* num_loc, Character* hero, uint8_t* buffer) {
    int offset = 0;
    uint32_t bytes = IntToBytesBigEndian(*num_loc);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(kLocationLength);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(kTraiderChance);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(kCaveChance);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(kTreasureChance);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = FloatToBytesBigEndian(kGain);
    memcpy(buffer + offset, &bytes, sizeof(float));
    offset += sizeof(float);
    memcpy(buffer + offset, &hero->race, sizeof(hero->race));
    offset += sizeof(hero->race);
    bytes = IntToBytesBigEndian(hero->strenhgt);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(hero->agility);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(hero->intellect);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(hero->damage);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(hero->physical_armor);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(hero->magic_armor);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(hero->critical_chance);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(hero->dodge_chance);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(hero->fright_chance);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(hero->experience);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(hero->hp);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(hero->money);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(hero->level);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = IntToBytesBigEndian(hero->experience_for_levelup);
    memcpy(buffer + offset, &bytes, sizeof(int));
    offset += sizeof(int);
    bytes = FloatToBytesBigEndian(hero->coefficient_experience);
    memcpy(buffer + offset, &bytes, sizeof(float));
    offset += sizeof(float);
    bytes = FloatToBytesBigEndian(hero->coefficient_critical_damage);
    memcpy(buffer + offset, &bytes, sizeof(float));
    offset += sizeof(float);
    for (int i = 0; i < 11; ++i) {
        bytes = IntToBytesBigEndian(hero->equipment[i]);
        memcpy(buffer + offset, &bytes, sizeof(int));
        offset += sizeof(int);
    }
    for (int i = 0; i < 5; ++i) {
        bytes = IntToBytesBigEndian(hero->spells[i]);
        memcpy(buffer + offset, &bytes, sizeof(int));
        offset += sizeof(int);
    }
    return buffer;
}

void Deserialization(int* num_loc, Character* hero, uint8_t* buffer) {
    uint32_t result = 0;
    int offset = 0;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    *num_loc = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    kLocationLength = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    kTraiderChance = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    kCaveChance = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    kTreasureChance = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    memcpy(&kGain, &result, sizeof(float));
    char str[10];
    for (size_t i = offset, j = 0; i < (offset + 10); ++i, ++j) str[j] = buffer[i];
    offset += 10;
    strcpy(hero->race, str);
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    hero->strenhgt = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    hero->agility = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    hero->intellect = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    hero->damage = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    hero->physical_armor = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    hero->magic_armor = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    hero->critical_chance = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    hero->dodge_chance = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    hero->fright_chance = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    hero->experience = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    hero->hp = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    hero->money = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    hero->level = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    hero->experience_for_levelup = result;
    result ^= result;
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    memcpy(&hero->coefficient_experience, &result, sizeof(float));
    for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
    offset += sizeof(int);
    memcpy(&hero->coefficient_critical_damage, &result, sizeof(float));
    for (int i = 0; i < 11; ++i) {
        result ^= result;
        for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
        offset += sizeof(int);
        hero->equipment[i] = result;
    }
    for (int i = 0; i < 5; ++i) {
        result ^= result;
        for (size_t i = offset; i < (offset + sizeof(uint32_t)); ++i) result = (result << 8) | buffer[i];
        offset += sizeof(int);
        hero->spells[i] = result;
    }
}

void sha_256(uint8_t* buffer, int size_buffer, uint8_t hash_bytes[]) {
    uint32_t H[8] = { 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };
    uint32_t K[64] = {
        0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,
        0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
        0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,
        0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
        0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,
        0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
        0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,
        0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
        0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,
        0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
        0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,
        0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
        0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,
        0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
        0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,
        0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
    };
    int dop_bit = 512 - (size_buffer * 8) - (8 * 8) - 8;
    int lot_block = 1;
    while (dop_bit < 0) dop_bit = (512 * (++lot_block)) - (size_buffer * 8) - (8 * 8) - 8;
    int new_size_buffer = size_buffer + (dop_bit / 8) + 9;
    buffer = (uint8_t*)realloc(buffer, new_size_buffer);
    buffer[size_buffer] = 0x01;
    memset(buffer + size_buffer + 1, 0, new_size_buffer - (size_buffer + 1));
    uint32_t len = IntToBytesBigEndian(size_buffer * 8);
    uint8_t* p = (uint8_t*)&len;
    for (int i = 0; i < 4; ++i) {
        buffer[192 - 4 + i] = p[i];
    }
    for (int i = 0; i < lot_block; ++i) {
        uint32_t W[64];
        for (int j = 0; j < 16; ++j) W[j] = buffer[(lot_block * i) + (j * 4)] << 24 | buffer[(lot_block * i) + (j * 4) + 1] << 16 | buffer[(lot_block * i) + (j * 4) + 2] << 8 | buffer[(lot_block * i) + (j * 4) + 3];
        for (int j = 16; j < 64; ++j) {
            uint32_t S0 = rotr(W[j - 15], 7) ^ rotr(W[j - 15], 18) ^ (W[j - 15] >> 3);
            uint32_t S1 = rotr(W[j - 2], 17) ^ rotr(W[j - 2], 19) ^ (W[j - 2] >> 10);
            W[j] = W[j - 16] + S0 + W[j - 7] + S1;
        }
        uint32_t a = H[0], b = H[1], c = H[2], d = H[3], e = H[4], f = H[5], g = H[6], h = H[7];
        for (int j = 0; j < 64; ++j) {
            uint32_t q = rotr(a, 2) ^ rotr(a, 13) ^ rotr(a, 22);
            uint32_t Ma = (a & b) ^ (a & c) ^ (b & c);
            uint32_t t2 = q + Ma;
            uint32_t p = rotr(e, 6) ^ rotr(e, 11) ^ rotr(e, 25);
            uint32_t Ch = (e & f) ^ ((~e) & g);
            uint32_t t1 = h + p + Ch + K[j] + W[j];
            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }
        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }
    for (int i = 0; i < 8; i++) {
        hash_bytes[i * 4] = (H[i] >> 24) & 0xFF; // Копируем каждый uint32_t в соответствующие 4 байта массива uint8_t
        hash_bytes[i * 4 + 1] = (H[i] >> 16) & 0xFF;
        hash_bytes[i * 4 + 2] = (H[i] >> 8) & 0xFF;
        hash_bytes[i * 4 + 3] = H[i] & 0xFF;
    }
}

void Save(int* num_loc, Character* hero) {
    FILE* file;
    size_t size_buffer = 35 * sizeof(int) + 3 * sizeof(float) + sizeof(hero->race);
    uint8_t* buffer = (uint8_t*)malloc(size_buffer);
    Serialization(num_loc, hero, buffer);
    uint8_t hash_bytes[32];
    sha_256(buffer, size_buffer, hash_bytes);
    fopen_s(&file, "save.sav", "wb");
    if (file != NULL) {
        fwrite(buffer, sizeof(uint8_t), size_buffer, file);
        uint8_t hash_bytes[32];
        sha_256(buffer, size_buffer, hash_bytes);
        fwrite(hash_bytes, sizeof(uint8_t), 32, file);
        fclose(file);
    }
    free(buffer);
}

int Load(int* num_loc, Character* hero) {
    FILE* file;
    fopen_s(&file, "save.sav", "rb"); // Открытие файла для чтения в бинарном режиме
    if (file == NULL) {
        attron(COLOR_PAIR(1) | A_UNDERLINE);
        mvprintw(rows / 2, (cols - 25) / 2, "У вас нет сохраненной игры");
        return 1;
    }
    fseek(file, 0, SEEK_END); // Переход в конец файла
    int file_size = ftell(file); // Получение размера файла
    fseek(file, 0, SEEK_SET); // Возвращение в начало файла
    uint8_t *buffer = (uint8_t*)malloc(file_size); 
    uint8_t hash_bytes_file[32];
    uint8_t hash_bytes[32];
    fread(buffer, sizeof(uint8_t), file_size, file);
    memcpy(hash_bytes_file, buffer + (file_size - 32), 32);
    fclose(file);
    sha_256(buffer, file_size - 32, hash_bytes);
    int comparison_result = memcmp(hash_bytes_file, hash_bytes, 32);
    if (comparison_result == 0) {
        Deserialization(num_loc, hero, buffer);
        free(buffer);
        return 0;
    } else {
        attron(COLOR_PAIR(1) | A_UNDERLINE);
        mvprintw(rows / 2, (cols - 31) / 2, "Нарушение целостности сохранения");
        free(buffer);
        return 1;
    }
    
    
}




