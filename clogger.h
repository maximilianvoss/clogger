/*
 * Copyright 2021 Maximilian Voss (maximilian@voss.rocks)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _CLOGGER_H
#define _CLOGGER_H

#include <stdio.h>

// Fallback if nothing is defined is CLOGGER_STDERR
#ifndef CLOGGER_STDOUT
#ifndef CLOGGER_STDERR
#ifndef CLOGGER_FILE
#ifndef CLOGGER_SDL
#define CLOGGER_STDERR
#endif
#endif
#endif
#endif

// CLOGGER_LEVEL
// 0 = ERROR
// 1 = INFO
// 2 = DEBUG
// 3 = TRACE
// Fallback if no log level is defined is ERROR

#ifndef CLOGGER_LEVEL
#define CLOGGER_LEVEL 0
#endif

#if CLOGGER_LEVEL < 3
#define LOG_TRACE(fmt, ...) { (void)(fmt); }
#endif

#if CLOGGER_LEVEL < 2
#define LOG_DEBUG(fmt, ...) { (void)(fmt); }
#endif

#if CLOGGER_LEVEL < 1
#define LOG_INFO(fmt, ...) { (void)(fmt); }
#endif

// STDOUT
#ifdef CLOGGER_STDOUT
#ifndef LOG_TRACE
#define LOG_TRACE(fmt, ...) { printf("\nTRACE: "); printf(fmt, ##__VA_ARGS__);}
#endif

#ifndef LOG_DEBUG
#define LOG_DEBUG(fmt, ...) { printf("\nDEBUG: "); printf(fmt, ##__VA_ARGS__);}
#endif

#ifndef LOG_INFO
#define LOG_INFO(fmt, ...) { printf("\nINFO: "); printf(fmt, ##__VA_ARGS__); }
#endif

#ifndef LOG_ERROR
#define LOG_ERROR(fmt, ...) { printf("\nERROR: "); printf(fmt, ##__VA_ARGS__);}
#endif
#endif // STDOUT

#ifdef CLOGGER_STDERR // STDERR
#ifndef LOG_TRACE
#define LOG_TRACE(fmt, ...) { printf("\nTRACE: "); fprintf(stderr, fmt, ##__VA_ARGS__);}
#endif

#ifndef LOG_DEBUG
#define LOG_DEBUG(fmt, ...) { fprintf(stderr, "\nDEBUG: "); fprintf(stderr, fmt, ##__VA_ARGS__);}
#endif

#ifndef LOG_INFO
#define LOG_INFO(fmt, ...) { fprintf(stderr, "\nINFO: "); fprintf(stderr, fmt, ##__VA_ARGS__); }
#endif

#ifndef LOG_ERROR
#define LOG_ERROR(fmt, ...) { fprintf(stderr, "\nERROR: "); fprintf(stderr, fmt, ##__VA_ARGS__);}
#endif
#endif // STDERR

#ifdef CLOGGER_FILE // FILE
#ifdef CLOGGER_LOGFILEDESC_ERROR

#ifndef CLOGGER_LOGFILEDESC_INFO
#define CLOGGER_LOGFILEDESC_ERROR
#endif

#ifndef CLOGGER_LOGFILEDESC_DEBUG
#define CLOGGER_LOGFILEDESC_INFO
#endif

#ifndef CLOGGER_LOGFILEDESC_TRACE
#define CLOGGER_LOGFILEDESC_DEBUG
#endif

#ifndef LOG_TRACE
#define LOG_TRACE(fmt, ...) { fprintf(CLOGGER_LOGFILEDESC_TRACE, fmt, ##__VA_ARGS__);}
#endif

#ifndef LOG_DEBUG
#define LOG_DEBUG(fmt, ...) { fprintf(CLOGGER_LOGFILEDESC_DEBUG, fmt, ##__VA_ARGS__);}
#endif

#ifndef LOG_INFO
#define LOG_INFO(fmt, ...) { fprintf(CLOGGER_LOGFILEDESC_INFO, fmt, ##__VA_ARGS__); }
#endif

#ifndef LOG_ERROR
#define LOG_ERROR(fmt, ...) { fprintf(CLOGGER_LOGFILEDESC_ERROR, fmt, ##__VA_ARGS__);}
#endif

#endif
#endif // STDFILE

#ifdef CLOGGER_SDL // SDL
#include <SDL_log.h>

#ifndef LOG_TRACE
#define LOG_TRACE(fmt, ...) { SDL_LogDebug(SDL_LOG_CATEGORY_CUSTOM, fmt, ##__VA_ARGS__);
#endif

#ifndef LOG_DEBUG
#define LOG_DEBUG(fmt, ...) { SDL_LogDebug(SDL_LOG_CATEGORY_TEST, fmt, ##__VA_ARGS__); }
#endif

#ifndef LOG_INFO
#define LOG_INFO(fmt, ...) { SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, fmt, ##__VA_ARGS__); }
#endif

#ifndef LOG_ERROR
#define LOG_ERROR(fmt, ...) { SDL_LogDebug(SDL_LOG_CATEGORY_ERROR, fmt, ##__VA_ARGS__); }
#endif
#endif // SDL


#endif
