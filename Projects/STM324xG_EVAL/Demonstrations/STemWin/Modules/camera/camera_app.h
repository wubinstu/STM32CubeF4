/**
  ******************************************************************************
  * @file    camera_app.h
  * @author  MCD Application Team
  * @brief   Camera application header file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CAMERA_APP_H
#define __CAMERA_APP_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Exported constants --------------------------------------------------------*/
#define CAMERA_FRAME_BUFFER 0x64100000
#define CAMERA_CVRT_BUFFER  0x64109600

#define RGB_HEADER_SIZE      54
#define IMAGE_BUFFER_SIZE   (160*120*2)     /* Size of RGB16 image */
#define MAX_IMAGE_SIZE      (160*120*3)      /* Size of RGB24 image  */
#define IMAGE_COLUMN_SIZE   160
#define IMAGE_LINE_SIZE     120
   
/* Exported types ------------------------------------------------------------*/
typedef union
{
  uint32_t d32;
  struct
  {
    uint32_t brightness     : 3;
    uint32_t contrast       : 3;    
  }b;
} CameraSettingsTypeDef;

/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void    CAMERA_Init(void);
void    CAMERA_Suspend(void);
void    CAMERA_Resume(void);
void    CAMERA_Stop(void);
void    CAMERA_Set_ContrastBrightness(uint32_t contrast_Level, uint32_t brightness_level);
void    CAMERA_SelectEffect(uint32_t effect);
uint8_t CAMERA_SaveToFile(uint8_t *path);
uint8_t CAMERA_GetState(void);
#ifdef __cplusplus
}
#endif

#endif /*__CAMERA_APP_H */
