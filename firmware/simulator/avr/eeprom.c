#include "eeprom.h"

#include <string.h>

#define EEPROM_SIZE 512

uint8_t eeprom[EEPROM_SIZE];

void reset(){
  memset(eeprom, 0, sizeof(eeprom));
}

uint8_t eeprom_read_byte (const uint8_t *addr){
  return eeprom[(long)addr];
}

/* Read one 16-bit word (little endian) from EEPROM address */
uint16_t eeprom_read_word (const uint16_t *addr){
  return (eeprom[(long)addr] << 8) & eeprom[(long)addr+1];
}

void eeprom_read_block (void *pointer_ram,
			const void *pointer_eeprom,
			size_t size){
  memcpy(pointer_ram, eeprom+(long)pointer_eeprom, size);
}

void eeprom_write_byte (uint8_t *addr, uint8_t value){
  eeprom[(long)addr] = value;
}

/* Write one 16-bit word (little endian) from EEPROM address */
void eeprom_write_word (uint16_t *addr,uint16_t value){ 
  eeprom[(long)addr] = (uint8_t)(value & 0xff);
  eeprom[(long)addr+1] = (value >> 8) & 0xff;
}

void eeprom_write_block (const void *pointer_ram,
			 void *pointer_eeprom,
			 size_t size){
  memcpy(eeprom+(long)pointer_eeprom, pointer_ram, size);
}