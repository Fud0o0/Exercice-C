#include <stdint.h>
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

struct png_sig { // 8 octets
    unsigned char magic[8];
};

struct png_chunk_header { // 8 octets
    uint32_t length; // big endian
    char type[4];
};

struct png_ihdr { // 13 octets
    uint32_t width;  // big endian
    uint32_t height; // big endian
    uint8_t bit_depth;
    uint8_t color_type;
    uint8_t compression;
    uint8_t filter;
    uint8_t interlace;
};

int main(int argc, char **argv) {
    assert(argc == 2);

    int fd = open(argv[1], O_RDONLY);
    assert(fd >= 0);

    // Vérifier la signature PNG
    struct png_sig sig;
    read(fd, &sig, sizeof(sig));

    assert(sig.magic[0] == 0x89);
    assert(sig.magic[1] == 'P');
    assert(sig.magic[2] == 'N');
    assert(sig.magic[3] == 'G');

    printf("Signature PNG: OK\n");

    // Lire les chunks
    struct png_chunk_header chunk;

    while (read(fd, &chunk, sizeof(chunk)) == sizeof(chunk)) {
        uint32_t len = ntohl(chunk.length);
        printf("[%.4s] %u octets\n", chunk.type, len);

        // Si c'est IHDR, on lit les détails
        if (chunk.type[0] == 'I' && chunk.type[1] == 'H'
         && chunk.type[2] == 'D' && chunk.type[3] == 'R') {
            struct png_ihdr ihdr;
            read(fd, &ihdr, sizeof(ihdr));
            printf("  %ux%u depth=%u color=%u\n",
                   ntohl(ihdr.width), ntohl(ihdr.height),
                   ihdr.bit_depth, ihdr.color_type);
            // Sauter le reste des données + CRC
            lseek(fd, len - sizeof(ihdr) + 4, SEEK_CUR);
        } else {
            // Sauter les données + CRC (4 octets)
            lseek(fd, len + 4, SEEK_CUR);
        }

        // IEND = fin
        if (chunk.type[0] == 'I' && chunk.type[1] == 'E'
         && chunk.type[2] == 'N' && chunk.type[3] == 'D')
            break;
    }

    close(fd);
}
