#ifndef __IMAGES_H__
#define __IMAGES_H__

#include <Arduino.h>

static unsigned char logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x80, 0x00, 0x00, 0x00, 0x08, 0x00,
    0x80, 0x9e, 0xe7, 0xf9, 0x09, 0x00, 0x80, 0x92, 0x24, 0x09, 0x08, 0x00,
    0x80, 0x92, 0x24, 0x09, 0x08, 0x00, 0x80, 0xf2, 0x3c, 0x0f, 0x08, 0x00,
    0x80, 0x02, 0x00, 0x00, 0x08, 0x00, 0x80, 0x02, 0x00, 0x00, 0x08, 0x00,
    0x80, 0xfe, 0xff, 0xff, 0x08, 0x00, 0x80, 0x00, 0x00, 0x80, 0x08, 0x00,
    0x80, 0x00, 0x00, 0x80, 0x08, 0x00, 0x80, 0x00, 0x00, 0x00, 0x08, 0x00,
    0x80, 0xfe, 0xff, 0xff, 0x0b, 0x00, 0x80, 0xfe, 0xff, 0xff, 0x0b, 0x00,
    0x80, 0xfe, 0xff, 0xff, 0x0b, 0x00, 0x80, 0x06, 0x00, 0x00, 0x03, 0x00,
    0x80, 0x06, 0x00, 0x00, 0xff, 0x01, 0x80, 0x76, 0xee, 0x00, 0xff, 0x01,
    0x80, 0x16, 0x21, 0x01, 0xff, 0x01, 0x80, 0x76, 0xe6, 0x00, 0x87, 0x01,
    0x80, 0x16, 0x28, 0x00, 0x87, 0x01, 0x80, 0x76, 0x27, 0x00, 0x87, 0x01,
    0x80, 0x06, 0x00, 0x00, 0x87, 0x01, 0x80, 0x06, 0x00, 0x00, 0x87, 0x01,
    0x80, 0x06, 0xe0, 0x0c, 0x87, 0x01, 0x80, 0x06, 0x00, 0x11, 0x87, 0x01,
    0x80, 0x06, 0xe0, 0x08, 0x87, 0x01, 0x80, 0x06, 0x00, 0x05, 0xff, 0x01,
    0x80, 0x06, 0xe0, 0x1c, 0xff, 0x01, 0x80, 0x06, 0x00, 0x00, 0xff, 0x01,
    0x80, 0x76, 0x01, 0x00, 0x03, 0x00, 0x80, 0xa6, 0x00, 0x00, 0x0b, 0x00,
    0x80, 0x56, 0x02, 0x00, 0x0b, 0x00, 0x80, 0x26, 0x03, 0x00, 0x0b, 0x00,
    0x80, 0x56, 0x01, 0x00, 0x0b, 0x00, 0x80, 0x06, 0x00, 0x00, 0x0b, 0x00,
    0x80, 0xfe, 0xff, 0xff, 0x0b, 0x00, 0x80, 0xfe, 0xff, 0xff, 0x0b, 0x00,
    0x80, 0x00, 0x00, 0x00, 0x08, 0x00, 0x80, 0xff, 0xff, 0xff, 0x0f, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static unsigned char skyline[] = {
    0xf6, 0x53, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xd9,
    0x5c, 0x16, 0xf8, 0xff, 0xff, 0x13, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x40, 0x25, 0x06, 0xab, 0xdd, 0xf6, 0xfd, 0x33, 0x18, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xa7, 0x26, 0x03, 0xfc, 0xff,
    0xff, 0xa3, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xb2,
    0x93, 0xa9, 0xfe, 0xee, 0xbf, 0x67, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x90, 0xf5, 0x82, 0x21, 0xda, 0xff, 0xfb, 0x41, 0x0c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68, 0xd9, 0xe9, 0x84, 0x7f, 0xdb,
    0xff, 0xc1, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x95,
    0x49, 0xa9, 0x6d, 0xff, 0xdf, 0x89, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x88, 0x62, 0x7f, 0x44, 0xff, 0x6d, 0xfe, 0x81, 0x05, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58, 0x47, 0x91, 0x88, 0x40, 0xff,
    0xdf, 0x12, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa, 0x7a,
    0x5f, 0x72, 0x2f, 0x00, 0xff, 0x17, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x2a, 0x31, 0x58, 0xe2, 0xfa, 0xff, 0xff, 0x3a, 0x03, 0x00,
    0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x55, 0x0d, 0x09, 0xb9, 0x57, 0xd5,
    0x6f, 0xfd, 0x06, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x9c, 0x39,
    0x2c, 0xf1, 0xde, 0xad, 0x1b, 0x00, 0x03, 0x00, 0x00, 0x40, 0x0a, 0x00,
    0x00, 0x80, 0xeb, 0x4e, 0x07, 0x5c, 0xbb, 0x7a, 0x16, 0x00, 0x00, 0x00,
    0x00, 0x90, 0x28, 0x00, 0x00, 0x00, 0xcd, 0x0f, 0xaa, 0xf8, 0x6b, 0xd3,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x25, 0x21, 0x00, 0x00, 0x00, 0x74, 0x23,
    0x23, 0xaf, 0xde, 0xae, 0x03, 0x00, 0x00, 0x00, 0x40, 0x24, 0x0a, 0x00,
    0x00, 0x00, 0xa0, 0x4f, 0x25, 0xfe, 0xb6, 0xba, 0x00, 0x00, 0x00, 0x00,
    0x48, 0x49, 0x11, 0x00, 0x00, 0x80, 0x80, 0xaa, 0x41, 0xed, 0xdb, 0x6a,
    0x00, 0x00, 0x00, 0x00, 0x12, 0x49, 0x24, 0x00, 0x00, 0x00, 0x04, 0xf4,
    0x95, 0x5d, 0xdf, 0xd6, 0x00, 0x00, 0x00, 0x80, 0xa4, 0x24, 0x09, 0x00,
    0x00, 0x80, 0x20, 0xca, 0x8a, 0xb7, 0xb5, 0x6d, 0x00, 0x00, 0x00, 0x50,
    0x95, 0x24, 0x11, 0x00, 0x00, 0x00, 0x02, 0x52, 0xbf, 0x6d, 0x6b, 0xdb,
    0x00, 0x00, 0x00, 0x24, 0x29, 0x49, 0x0a, 0x00, 0x00, 0x10, 0x90, 0xa8,
    0xfa, 0x76, 0xad, 0xba, 0x00, 0x00, 0x00, 0x4d, 0x45, 0x89, 0x10, 0x00,
    0x00, 0x00, 0xa0, 0x24, 0xcb, 0xdf, 0xab, 0xd6, 0x00, 0x00, 0xa0, 0x94,
    0x12, 0x52, 0x0a, 0x00, 0x00, 0x20, 0x98, 0xa2, 0xb4, 0x6a, 0xdd, 0xba,
    0x00, 0x00, 0xb4, 0x34, 0xb2, 0x84, 0x08, 0x00, 0x00, 0x00, 0xa5, 0x28,
    0xb4, 0x6d, 0x55, 0xab, 0x00, 0x00, 0x2a, 0x49, 0x85, 0x14, 0x01, 0x00,
    0x00, 0x84, 0x52, 0x16, 0xa5, 0xb6, 0xdb, 0x76, 0x00, 0x80, 0x6a, 0x2a,
    0x2a, 0x51, 0x0a, 0x00, 0x00, 0xc8, 0x14, 0x49, 0x21, 0x6d, 0xb5, 0xd6,
    0x00, 0xb0, 0x94, 0xa9, 0x24, 0x85, 0x04, 0x00, 0x00, 0x30, 0x65, 0xa4,
    0xd4, 0xb4, 0xeb, 0xad, 0x00, 0x26, 0x75, 0xa2, 0x44, 0x28, 0x01, 0x00,
    0x00, 0x24, 0xa9, 0x2c, 0x10, 0x50, 0x5b, 0xbb, 0x80, 0x4e, 0x54, 0x29,
    0x55, 0x45, 0x02, 0x00, 0x00, 0x53, 0x14, 0x8a, 0x2e, 0x40, 0xd7, 0x66,
    0x50, 0x59, 0x55, 0x52, 0x44, 0x94, 0x02, 0x00, 0x00, 0x48, 0x85, 0x13,
    0x05, 0x81, 0xbe, 0xdd, 0x54, 0x97, 0xd2, 0x24, 0x89, 0x22, 0x00, 0x00,
    0x00, 0x43, 0x71, 0xe0, 0x42, 0x38, 0xe8, 0xb6, 0x56, 0xb4, 0xa4, 0x4a,
    0x29, 0xaa, 0x02, 0x00, 0x00, 0x4a, 0x92, 0x34, 0x02, 0x04, 0xa1, 0xb7,
    0x4b, 0xab, 0xd2, 0x50, 0x44, 0x40, 0x01, 0x00, 0x00, 0x14, 0x86, 0x86,
    0x90, 0x83, 0x40, 0xfe, 0x53, 0x3a, 0x84, 0xa5, 0x94, 0x15, 0x00, 0x00,
    0x00, 0x94, 0x4a, 0x0a, 0xc1, 0x90, 0x04, 0xda, 0xab, 0xae, 0xb2, 0x52,
    0x49, 0x52, 0x00, 0x00, 0x00, 0x50, 0xe0, 0x90, 0x34, 0x40, 0x80, 0xea,
    0xda, 0xb5, 0x14, 0x45, 0x49, 0x84, 0x00, 0x00, 0x00, 0xa8, 0x92, 0x42,
    0x0c, 0x25, 0x90, 0xa1, 0xb5, 0x6a, 0x4b, 0x95, 0x94, 0x32, 0x00, 0x00,
    0x00, 0x44, 0x2c, 0x52, 0x17, 0x90, 0x74, 0x88, 0xeb, 0xdd, 0x02, 0x43,
    0x91, 0x24, 0x00, 0x00, 0x00, 0x14, 0x29, 0xe4, 0xa2, 0x10, 0x0c, 0x00,
    0xaf, 0xbb, 0x54, 0x2a, 0x49, 0x12, 0x00, 0x00, 0x00, 0x60, 0x42, 0xb8,
    0x48, 0x48, 0x83, 0x04, 0x4d, 0xe6, 0x81, 0x12, 0x11, 0x12, 0x00, 0x00,
    0x00, 0xa0, 0x88, 0x2e, 0x0a, 0xd5, 0x11, 0x20, 0xb7, 0x9a, 0x34, 0x4a,
    0xa5, 0x04, 0x00, 0x00, 0x00, 0x10, 0x4a, 0x8b, 0x28, 0x3a, 0x80, 0x04,
    0xfd, 0x5a, 0xa1, 0x8c, 0x94, 0x14, 0x00, 0x00, 0x00, 0x90, 0x50, 0x2b,
    0x89, 0x0e, 0x04, 0x20, 0xaa, 0xab, 0x0a, 0x25, 0x21, 0x09, 0x00, 0x00,
    0x00, 0x00, 0x55, 0x42, 0xd4, 0x2f, 0x91, 0x04, 0x9b, 0x82, 0x26, 0x49,
    0x4a, 0x02, 0x00, 0x00, 0x00, 0x80, 0xb4, 0x4c, 0xe1, 0x23, 0x00, 0x20,
    0x65, 0x55, 0x91, 0x2a, 0x91, 0x04, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x09,
    0xbd, 0x88, 0xa4, 0x04, 0xde, 0x48, 0x47, 0x48, 0x92, 0x04, 0x00, 0x00,
    0x00, 0xc0, 0xa2, 0x32, 0x7e, 0x91, 0x00, 0x40, 0x35, 0x51, 0x28, 0x95,
    0x4a, 0x02, 0x00, 0x00, 0x00, 0x00, 0x89, 0xa8, 0x27, 0x05, 0x95, 0xe4,
    0x57, 0xd2, 0x2a, 0x25, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa2, 0xe2,
    0xab, 0x24, 0x12, 0x78, 0x27, 0x09, 0x15, 0x8a, 0x24, 0x01, 0x00, 0x00,
    0x00, 0x80, 0x48, 0x7c, 0x5a, 0x49, 0x44, 0x1f, 0x4d, 0xaa, 0xac, 0x98,
    0x2a, 0x01, 0x00, 0x00, 0x00, 0x00, 0x29, 0xbd, 0xa9, 0x92, 0x48, 0x27,
    0x2b, 0x15, 0x43, 0x12, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd4, 0x8b,
    0x4d, 0x56, 0xf2, 0x81, 0xaa, 0x22, 0x4d, 0x54, 0x9a, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x68, 0x2b, 0x9b, 0x4a, 0xfc, 0x14, 0xaa, 0x4a, 0x29, 0x11,
    0xab, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xbd, 0xc8, 0x2a, 0x91, 0x3f, 0x41,
    0xaa, 0x90, 0x32, 0xb2, 0x16, 0x00, 0x00, 0x80, 0x0a, 0x00, 0x5c, 0x92,
    0xaf, 0xea, 0xaf, 0x0a, 0x6a, 0x25, 0x9a, 0x88, 0x55, 0x00, 0x00, 0x60,
    0x1b, 0x20, 0xa1, 0x92, 0xaa, 0xf2, 0x13, 0x96, 0x3a, 0xa9, 0x24, 0x51,
    0x17, 0x00, 0x00, 0x54, 0x35, 0x00, 0x24, 0xa5, 0x9a, 0xfe, 0x28, 0x28,
    0xaa, 0x54, 0xaa, 0x64, 0x15, 0x00, 0x00, 0x5a, 0x2b, 0x00, 0xa0, 0xf4,
    0x52, 0x1f, 0x95, 0x50, 0xae, 0x0a, 0xa5, 0xa8, 0x2b, 0x00, 0x80, 0xb6,
    0x6a, 0x00, 0x08, 0xa1, 0xf4, 0x57, 0x20, 0x52, 0x55, 0x52, 0x2a, 0xb2,
    0x16, 0x00, 0x60, 0x55, 0x1b, 0x00, 0x61, 0x96, 0xf4, 0x25, 0xd5, 0x94,
    0x55, 0x85, 0x68, 0x72, 0x05, 0x00, 0x54, 0x5f, 0x75, 0x00, 0x84, 0x34,
    0xfd, 0x47, 0x80, 0x21, 0xaa, 0xa9, 0x94, 0xd8, 0x0a, 0x00, 0x6a, 0x55,
    0x55, 0x00, 0x52, 0x45, 0xaf, 0x81, 0x2a, 0x4d, 0xd4, 0xa3, 0x48, 0xb9,
    0x06, 0x40, 0xd5, 0x57, 0x55, 0x00, 0x10, 0xed, 0x3f, 0x17, 0x05, 0x2a,
    0xb5, 0x28, 0x52, 0xb6, 0x09, 0xa0, 0x56, 0x6f, 0x6b, 0x00, 0x24, 0xfd,
    0x02, 0x23, 0xa2, 0x8c};

static unsigned char moon[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xe5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9b, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xab, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x7f, 0x57, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xad, 0xf8, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0x5b, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x7f, 0xab, 0xe2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xaa, 0xd4, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x57, 0xc5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x5f, 0x55, 0xa9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x55, 0x05, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xaf,
    0x56, 0xa9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xad, 0x0a, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xaf, 0xb6, 0x52, 0xfe, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf,
    0xad, 0x8a, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x77, 0x5b, 0x29, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0x57, 0x23, 0xfc, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb,
    0xba, 0x8a, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xbf, 0xab, 0x22, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x77, 0xb5, 0x8a, 0xf8, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xee,
    0xd6, 0x12, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x5b, 0xb5, 0x4a, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xaa, 0x12, 0xf1, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xad,
    0xb6, 0x55, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x57, 0xb5, 0x8a, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xad, 0x56, 0x8b, 0xfa, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xab,
    0xda, 0x2a, 0xf2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xbf, 0x2a, 0x55, 0x95, 0xf4, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xab, 0x5a, 0x95, 0xf2, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x5f, 0x55,
    0xaa, 0x4a, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x7f, 0xab, 0xa8, 0x12, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xaa, 0x2a, 0xa5, 0xfc, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x96,
    0x54, 0x2a, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xb7, 0x2a, 0x89, 0x54, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0x55, 0x29, 0x29, 0xfd, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x5f, 0x15,
    0x92, 0x4a, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x6b, 0xb5, 0x24, 0x54, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xde, 0x4a, 0xaa, 0x12, 0xfe, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xab, 0x92,
    0x28, 0x84, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x56, 0x2d, 0x45, 0x15, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x5d, 0x49, 0x4a, 0x50, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x55, 0x95,
    0x28, 0x85, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xbf, 0xab, 0x92, 0x42, 0xd1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x5a, 0x25, 0x14, 0xe4, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x56, 0x4a,
    0x81, 0xe4, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xbf, 0x55, 0x29, 0x2a, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x55, 0xa5, 0x00, 0xf9, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0x56, 0x12,
    0x25, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xdf, 0xaa, 0x44, 0x84, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x95, 0x12, 0xd1, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x55, 0x52,
    0xc4, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xaf, 0x4a, 0x89, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x12, 0x92, 0xfc, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x55, 0xa9,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xab, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff};
#endif