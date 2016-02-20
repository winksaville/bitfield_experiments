#include <stdio.h>

struct one_bit_fields {
  _Bool b0:1;
  signed long long int b1:1;
  unsigned long long int b2:1;
};

_Static_assert(sizeof(struct one_bit_fields) == 8,
    L"one_bit_fields is not 8 bytes");

struct packed_one_bit_fields {
  _Bool b0:1;
  signed long long int b1:1;
  unsigned long long int b2:1;
} __attribute__((__packed__));

_Static_assert(sizeof(struct packed_one_bit_fields) == 1,
    L"packed_one_bit_fields is not 1 byte");

struct unsigned_long_long_bit_fields {
  unsigned long long int b0:31;
  unsigned long long int b1:32;
  unsigned long long b2:33;
};

_Static_assert(sizeof(struct unsigned_long_long_bit_fields) == 16,
    L"unsigned_long_long_bit_fields is not 16 bytes");


struct packed_unsigned_long_long_bit_fields {
  unsigned long long int b0:31;
  unsigned long long int b1:32;
  unsigned long long int b2:33;
} __attribute__((__packed__));

_Static_assert(sizeof(struct packed_unsigned_long_long_bit_fields) == 12,
    L"packed_unsigned_long_long_bit_fields is not 12 bytes");


#define type_to_str(__x) _Generic((__x), \
  _Bool : "_Bool", \
  char : "char", \
  unsigned char : "unsigned char", \
  short : "short", \
  unsigned short : "unsigned short", \
  int : "int", \
  unsigned int : "unsigned int", \
  long : "long", \
  unsigned long : "unsigned long", \
  long long : "long long", \
  unsigned long long : "unsigned long long", \
  default : "unknown type")

int main(void) {
  const int cf = 32;
  volatile int vf = 32;
  struct one_bit_fields ob = { .b0 = 1, .b1 = 1, .b2 = 1 };

  printf("ob.b0=%d (0x%x) type=%s\n", ob.b0, ob.b0, type_to_str(ob.b0));
  printf("       >>1 =0x%016x\n", ob.b0 >> 1);
  printf("  (ull)>>1 =0x%016llx\n", (unsigned long long)ob.b0 >> 1);
  printf("       >>0 =0x%016x\n", ob.b0 >> 0);
  printf("  (ull)>>0 =0x%016llx\n", (unsigned long long)ob.b0 >> 0);
  printf("       <<0 =0x%016x\n", ob.b0 << 0);
  printf("  (ull)<<0 =0x%016llx\n", (unsigned long long)ob.b0 << 0);
  printf("       <<1 =0x%016x\n", ob.b0 << 1);
  printf("  (ull)<<1 =0x%016llx\n", (unsigned long long)ob.b0 << 1);
  printf("       <<2 =0x%016x\n", ob.b0 << 2);
  printf("  (ull)<<2 =0x%016llx\n", (unsigned long long)ob.b0 << 2);
  printf("       <<29=0x%016x\n", ob.b0 << 29);
  printf("  (ull)<<29=0x%016llx\n", (unsigned long long)ob.b0 << 29);
  printf("       <<30=0x%016x\n", ob.b0 << 30);
  printf("  (ull)<<30=0x%016llx\n", (unsigned long long)ob.b0 << 30);
  printf("       <<31=0x%016x\n", ob.b0 << 31);
  printf("  (ull)<<31=0x%016llx\n", (unsigned long long)ob.b0 << 31);
  printf("       <<32=0x%016x\n", ob.b0 << 32);
  printf("  (ull)<<32=0x%016llx\n", (unsigned long long)ob.b0 << 32);
  printf("     <<cf32=0x%016x\n", ob.b0 << cf);
  printf("     <<vf32=0x%016x\n", ob.b0 << vf);

  printf("ob.b1=%d (0x%x) type=%s\n", ob.b1, ob.b1, type_to_str(ob.b1));
  printf("       >>1 =0x%016x\n", ob.b1 >> 1);
  printf("  (ull)>>1 =0x%016llx\n", (unsigned long long)ob.b1 >> 1);
  printf("       >>0 =0x%016x\n", ob.b1 >> 0);
  printf("  (ull)>>0 =0x%016llx\n", (unsigned long long)ob.b1 >> 0);
  printf("       <<0 =0x%016x\n", ob.b1 << 0);
  printf("  (ull)<<0 =0x%016llx\n", (unsigned long long)ob.b1 << 0);
  printf("       <<1 =0x%016x\n", ob.b1 << 1);
  printf("  (ull)<<1 =0x%016llx\n", (unsigned long long)ob.b1 << 1);
  printf("       <<2 =0x%016x\n", ob.b1 << 2);
  printf("  (ull)<<2 =0x%016llx\n", (unsigned long long)ob.b1 << 2);
  printf("       <<29=0x%016x\n", ob.b1 << 29);
  printf("  (ull)<<29=0x%016llx\n", (unsigned long long)ob.b1 << 29);
  printf("       <<30=0x%016x\n", ob.b1 << 30);
  printf("  (ull)<<30=0x%016llx\n", (unsigned long long)ob.b1 << 30);
  printf("       <<31=0x%016x\n", ob.b1 << 31);
  printf("  (ull)<<31=0x%016llx\n", (unsigned long long)ob.b1 << 31);
  printf("       <<32=0x%016x\n", ob.b1 << 32);
  printf("  (ull)<<32=0x%016llx\n", (unsigned long long)ob.b1 << 32);
  printf("     <<cf32=0x%016x\n", ob.b1 << cf);
  printf("     <<vf32=0x%016x\n", ob.b1 << vf);

  printf("ob.b2=%d (0x%x) type=%s\n", ob.b2, ob.b2, type_to_str(ob.b2));
  printf("       >>1 =0x%016x\n", ob.b2 >> 1);
  printf("  (ull)>>1 =0x%016llx\n", (unsigned long long)ob.b2 >> 1);
  printf("       >>0 =0x%016x\n", ob.b2 >> 0);
  printf("  (ull)>>0 =0x%016llx\n", (unsigned long long)ob.b2 >> 0);
  printf("       <<0 =0x%016x\n", ob.b2 << 0);
  printf("  (ull)<<0 =0x%016llx\n", (unsigned long long)ob.b2 << 0);
  printf("       <<1 =0x%016x\n", ob.b2 << 1);
  printf("  (ull)<<1 =0x%016llx\n", (unsigned long long)ob.b2 << 1);
  printf("       <<2 =0x%016x\n", ob.b2 << 2);
  printf("  (ull)<<2 =0x%016llx\n", (unsigned long long)ob.b2 << 2);
  printf("       <<29=0x%016x\n", ob.b2 << 29);
  printf("  (ull)<<29=0x%016llx\n", (unsigned long long)ob.b2 << 29);
  printf("       <<30=0x%016x\n", ob.b2 << 30);
  printf("  (ull)<<30=0x%016llx\n", (unsigned long long)ob.b2 << 30);
  printf("       <<31=0x%016x\n", ob.b2 << 31);
  printf("  (ull)<<31=0x%016llx\n", (unsigned long long)ob.b2 << 31);
  printf("       <<32=0x%016x\n", ob.b2 << 32);
  printf("  (ull)<<32=0x%016llx\n", (unsigned long long)ob.b2 << 32);
  printf("     <<cf32=0x%016x\n", ob.b2 << cf);
  printf("     <<vf32=0x%016x\n", ob.b2 << vf);

  struct unsigned_long_long_bit_fields ullb = {
    .b0 = 0x07FFFFFFF,
    .b1 = 0x0FFFFFFFF,
    .b2 = 0x1FFFFFFFF,
  };

  printf("ullb.b0=%u (0x%x) type=%s\n", ullb.b0, ullb.b0, type_to_str(ullb.b0));
  printf("       >>1 =0x%016x\n", ullb.b0 >> 1);
  printf("  (ull)>>1 =0x%016llx\n", (unsigned long long)ullb.b0 >> 1);
  printf("       >>0 =0x%016x\n", ullb.b0 >> 0);
  printf("  (ull)>>0 =0x%016llx\n", (unsigned long long)ullb.b0 >> 0);
  printf("       <<0 =0x%016x\n", ullb.b0 << 0);
  printf("  (ull)<<0 =0x%016llx\n", (unsigned long long)ullb.b0 << 0);
  printf("       <<1 =0x%016x\n", ullb.b0 << 1);
  printf("  (ull)<<1 =0x%016llx\n", (unsigned long long)ullb.b0 << 1);
  printf("       <<2 =0x%016x\n", ullb.b0 << 2);
  printf("  (ull)<<2 =0x%016llx\n", (unsigned long long)ullb.b0 << 2);
  printf("       <<29=0x%016x\n", ullb.b0 << 29);
  printf("  (ull)<<29=0x%016llx\n", (unsigned long long)ullb.b0 << 29);
  printf("       <<30=0x%016x\n", ullb.b0 << 30);
  printf("  (ull)<<30=0x%016llx\n", (unsigned long long)ullb.b0 << 30);
  printf("       <<31=0x%016x\n", ullb.b0 << 31);
  printf("  (ull)<<31=0x%016llx\n", (unsigned long long)ullb.b0 << 31);
  printf("       <<32=0x%016x\n", ullb.b0 << 32);
  printf("  (ull)<<32=0x%016llx\n", (unsigned long long)ullb.b0 << 32);
  printf("     <<cf32=0x%016x\n", ullb.b0 << cf);
  printf("     <<vf32=0x%016x\n", ullb.b0 << vf);

  printf("ullb.b1=%u (0x%x) type=%s\n", ullb.b1, ullb.b1, type_to_str(ullb.b1));
  printf("       >>1 =0x%016x\n", ullb.b1 >> 1);
  printf("  (ull)>>1 =0x%016llx\n", (unsigned long long)ullb.b1 >> 1);
  printf("       >>0 =0x%016x\n", ullb.b1 >> 0);
  printf("  (ull)>>0 =0x%016llx\n", (unsigned long long)ullb.b1 >> 0);
  printf("       <<0 =0x%016x\n", ullb.b1 << 0);
  printf("  (ull)<<0 =0x%016llx\n", (unsigned long long)ullb.b1 << 0);
  printf("       <<1 =0x%016x\n", ullb.b1 << 1);
  printf("  (ull)<<1 =0x%016llx\n", (unsigned long long)ullb.b1 << 1);
  printf("       <<2 =0x%016x\n", ullb.b1 << 2);
  printf("  (ull)<<2 =0x%016llx\n", (unsigned long long)ullb.b1 << 2);
  printf("       <<29=0x%016x\n", ullb.b1 << 29);
  printf("  (ull)<<29=0x%016llx\n", (unsigned long long)ullb.b1 << 29);
  printf("       <<30=0x%016x\n", ullb.b1 << 30);
  printf("  (ull)<<30=0x%016llx\n", (unsigned long long)ullb.b1 << 30);
  printf("       <<31=0x%016x\n", ullb.b1 << 31);
  printf("  (ull)<<31=0x%016llx\n", (unsigned long long)ullb.b1 << 31);
  printf("       <<32=0x%016x\n", ullb.b1 << 32);
  printf("  (ull)<<32=0x%016llx\n", (unsigned long long)ullb.b1 << 32);
  printf("     <<cf32=0x%016x\n", ullb.b1 << cf);
  printf("     <<vf32=0x%016x\n", ullb.b1 << vf);

  printf("ullb.b2=%llu (0x%llx) type=%s\n", ullb.b2, ullb.b2, type_to_str(ullb.b2));
  printf("       >>1 =0x%016llx\n", ullb.b2 >> 1);
  printf("  (ull)>>1 =0x%016llx\n", (unsigned long long)ullb.b2 >> 1);
  printf("       >>0 =0x%016llx\n", ullb.b2 >> 0);
  printf("  (ull)>>0 =0x%016llx\n", (unsigned long long)ullb.b2 >> 0);
  printf("       <<0 =0x%016llx\n", ullb.b2 << 0);
  printf("  (ull)<<0 =0x%016llx\n", (unsigned long long)ullb.b2 << 0);
  printf("       <<1 =0x%016llx\n", ullb.b2 << 1);
  printf("  (ull)<<1 =0x%016llx\n", (unsigned long long)ullb.b2 << 1);
  printf("       <<2 =0x%016llx\n", ullb.b2 << 2);
  printf("  (ull)<<2 =0x%016llx\n", (unsigned long long)ullb.b2 << 2);
  printf("       <<29=0x%016llx\n", ullb.b2 << 29);
  printf("  (ull)<<29=0x%016llx\n", (unsigned long long)ullb.b2 << 29);
  printf("       <<30=0x%016llx\n", ullb.b2 << 30);
  printf("  (ull)<<30=0x%016llx\n", (unsigned long long)ullb.b2 << 30);
  printf("       <<31=0x%016llx\n", ullb.b2 << 31);
  printf("  (ull)<<31=0x%016llx\n", (unsigned long long)ullb.b2 << 31);
  printf("       <<32=0x%016llx\n", ullb.b2 << 32);
  printf("  (ull)<<32=0x%016llx\n", (unsigned long long)ullb.b2 << 32);
  printf("     <<cf32=0x%016llx\n", ullb.b2 << cf);
  printf("     <<vf32=0x%016llx\n", ullb.b2 << vf);

  return 0;
}