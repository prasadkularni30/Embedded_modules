#ifndef __MY_IOCTL_H__
#define __MY_IOCTL_H__

#define GET_EVEN	_IOR('Z', 122, unsigned int *)
#define GET_ODD 	_IOR('Z', 123, unsigned int *)
#define DISPLAY_EVEN	_IOR('Z', 124, unsigned int *)
#define DISPLAY_ODD 	_IOR('Z', 125, unsigned int *)
#define DELETE_EVEN	_IOR('Z', 126, unsigned int *)
#define DELETE_ODD 	_IOR('Z', 127, unsigned int *)

#endif
