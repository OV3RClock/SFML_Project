#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>

#include "Tilemap.h"

using namespace sf;
using namespace std;

string grass = {
"226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 "
"254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 "
"282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 "
"310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 "
"226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 "
"254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 "
"282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 "
"310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 "
"226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 "
"254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 "
"282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 "
"310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 "
"226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 "
"254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 "
"282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 "
"310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 "
"226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 "
"254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 "
"282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 "
"310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 "
"226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 "
"254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 "
"282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 "
"310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 "
"226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 "
"254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 "
"282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 "
"310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 "
"226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 "
"254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 "
"282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 "
"310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 "
"226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 "
"254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 "
"282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 284 285 282 283 "
"310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 312 313 310 311 "
"226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 228 229 226 227 "
"254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255 256 257 254 255"
};
string ground = {
"672 672 672 672 405 405 405 405 490 433 434 262 262 262 262 262 262 262 263 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 289 345 262 262 262 262 262 262 432 489 405 405 405 "
"672 672 672 672 405 405 405 405 406 262 262 262 262 262 346 290 290 290 291 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 289 345 262 262 262 262 262 262 404 405 405 405 "
"672 672 672 667 405 405 405 405 406 262 262 262 346 290 291 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 289 290 345 262 262 262 262 404 405 405 405 "
"672 672 672 405 405 405 405 405 406 262 262 262 263 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 261 262 262 262 262 404 405 405 405 "
"672 672 672 405 405 405 405 490 434 262 262 262 318 235 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 289 345 262 262 262 404 405 405 405 "
"672 672 672 405 405 405 405 406 262 262 262 262 262 263 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 261 262 262 376 461 405 405 405 "
"672 672 667 405 405 405 405 406 262 262 262 262 262 263 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 261 262 262 404 405 405 405 405 "
"672 672 405 405 405 405 405 406 262 262 262 262 262 263 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 233 234 317 262 376 461 405 405 405 405 "
"672 667 405 405 405 405 490 434 262 262 262 262 346 291 0 0 0 0 0 0 0 0 0 236 237 237 237 237 237 238 0 0 0 0 0 0 0 0 0 0 261 262 262 262 404 405 405 405 405 405 "
"672 405 405 405 405 490 434 262 262 262 262 262 263 0 0 0 0 0 0 0 0 0 0 264 265 265 265 265 265 266 0 0 0 0 0 0 0 0 0 233 317 262 262 262 404 405 405 405 405 405 "
"667 405 405 405 405 406 262 262 262 262 262 346 291 0 0 0 0 0 0 0 0 0 0 264 265 265 265 265 265 266 0 0 0 0 0 0 0 0 0 261 262 262 262 262 404 405 405 405 405 405 "
"405 405 405 405 490 434 262 262 262 262 262 263 0 0 0 0 0 0 0 0 0 0 0 264 265 265 265 265 265 266 0 0 0 0 0 0 0 0 0 261 262 262 262 262 432 489 405 405 405 405 "
"405 405 405 405 406 262 262 262 262 262 262 263 0 0 0 0 0 0 0 0 0 0 0 264 265 265 265 265 265 266 0 0 0 0 0 0 0 0 0 261 262 262 262 262 262 404 405 405 405 405 "
"405 405 405 490 434 262 262 262 262 262 346 291 0 0 0 0 0 0 0 0 0 0 0 292 293 348 265 349 293 294 0 0 0 0 0 0 0 0 0 289 345 262 262 262 262 432 489 405 405 405 "
"405 405 405 406 262 262 262 262 262 262 263 0 0 0 0 0 0 0 0 0 0 0 0 0 0 264 265 266 0 0 0 0 0 0 0 0 0 0 0 0 289 345 262 262 262 262 404 405 405 405 "
"405 405 405 406 262 262 262 262 262 262 263 0 0 0 0 0 0 0 0 0 0 0 0 0 0 264 265 266 0 0 0 0 0 0 0 0 0 0 0 0 0 289 345 262 262 262 404 405 405 405 "
"405 405 405 406 262 262 262 262 262 262 263 0 0 0 0 0 0 0 0 0 0 0 0 0 0 264 265 266 0 0 0 0 0 0 0 0 0 0 0 0 0 0 261 262 262 262 404 405 405 405 "
"405 405 405 406 262 262 262 262 262 346 291 0 0 0 0 0 0 0 0 0 0 0 0 0 0 264 265 266 0 0 0 0 0 0 0 0 0 0 0 0 0 0 261 262 262 376 461 405 405 405 "
"405 405 405 406 262 262 262 262 262 263 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 264 265 266 0 0 0 0 0 0 0 0 0 0 0 0 0 233 317 262 262 404 405 405 405 405 "
"405 405 405 406 262 262 262 262 262 318 235 0 0 0 0 0 0 0 0 0 0 0 0 0 0 264 265 266 0 0 0 0 0 0 0 0 0 0 0 0 233 317 262 262 376 461 405 405 405 405 "
"405 405 405 406 262 262 262 262 262 262 263 0 0 0 0 0 0 0 0 0 0 0 0 0 0 292 293 294 0 0 0 0 0 0 0 0 0 0 0 233 317 262 262 376 461 405 405 405 405 405 "
"405 405 405 406 262 262 262 262 262 262 318 235 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 261 262 262 376 461 405 405 405 405 405 405 "
"405 405 405 462 378 262 262 262 262 262 262 318 235 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 261 262 262 404 405 405 405 405 405 405 405 "
"405 405 405 405 406 262 262 262 262 262 262 262 318 235 0 0 0 0 0 0 0 0 0 0 258 259 259 259 260 0 0 0 0 0 0 0 0 0 233 317 262 262 404 405 405 405 405 405 405 696 "
"405 405 405 405 406 262 262 262 262 262 262 262 262 318 234 234 235 0 0 0 0 0 0 0 286 342 259 343 288 0 0 0 0 0 0 233 234 234 317 262 262 376 461 405 405 405 405 405 696 672 "
"405 405 405 405 462 378 262 262 262 262 262 262 262 262 262 262 318 234 234 234 234 234 234 235 0 258 259 260 0 0 0 233 234 234 234 317 262 262 262 262 262 404 405 405 405 405 405 696 672 672 "
"405 405 405 405 405 406 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 318 235 286 287 288 0 0 233 317 262 262 262 262 262 262 262 262 262 404 405 405 405 405 405 672 672 672 "
"405 405 405 405 405 462 378 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 318 234 234 234 234 234 317 262 262 262 262 262 262 262 262 262 376 461 405 405 405 405 405 672 672 672 "
"405 405 405 405 405 405 406 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 376 461 405 405 405 405 405 696 672 672 672 "
"405 405 405 405 405 405 462 377 378 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 376 461 405 405 405 405 405 405 672 672 672 672 "
"405 405 405 405 405 405 405 405 462 377 377 378 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 376 377 461 405 405 405 405 405 405 405 672 672 672 672 "
"433 433 489 405 405 405 405 405 405 405 405 462 378 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 376 461 405 405 405 405 405 405 405 405 405 672 672 672 672 "
"262 262 432 433 489 405 405 405 405 405 405 405 462 378 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 262 376 377 377 377 461 405 405 405 405 405 405 405 405 405 696 672 672 672 672 "
"262 262 262 262 432 489 405 405 405 405 405 405 405 462 377 378 262 262 262 262 262 262 262 262 262 262 262 262 376 377 377 461 405 405 405 405 405 405 405 405 405 405 405 405 405 672 672 672 672 672 "
"262 262 262 262 262 432 433 489 405 405 405 405 405 405 405 462 377 378 262 262 262 262 262 262 262 262 376 377 461 405 405 405 405 405 405 405 405 405 405 405 405 405 405 405 696 672 672 672 672 672 "
"262 262 262 262 262 262 262 432 433 489 405 405 405 405 405 405 405 462 377 377 378 262 262 262 376 377 461 405 405 405 405 405 405 405 405 405 405 405 405 405 405 405 405 696 672 672 672 672 672 672 "
"262 262 262 262 262 262 262 262 262 432 489 405 405 405 405 405 405 405 405 405 462 377 377 377 461 405 405 405 405 405 405 405 405 405 405 405 405 405 405 405 405 696 672 672 672 672 672 672 672 672 "
"262 262 262 262 262 262 262 262 262 262 432 489 405 405 405 405 405 405 405 405 405 405 405 405 405 405 405 405 405 405 405 405 405 405 405 405 405 696 672 672 672 672 672 672 672 672 672 672 672 672"
};
string world = {
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 365 366 366 366 366 366 366 366 366 366 366 367 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 365 366 366 425 0 0 0 0 0 0 0 0 0 0 424 366 366 367 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 365 366 425 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 424 366 367 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 393 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 401 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 400 0 0 0 22 157 157 157 157 157 157 157 157 157 157 157 157 157 22 0 0 424 366 367 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 365 425 0 0 0 50 185 185 185 185 185 185 185 185 185 185 185 185 185 50 0 0 0 0 401 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 400 0 0 0 0 128 0 0 0 0 0 0 0 0 0 0 0 0 0 128 0 0 0 0 401 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 400 0 0 0 0 128 0 0 0 0 0 0 0 0 0 0 0 0 0 128 0 0 0 0 424 367 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 365 425 0 0 0 0 128 0 0 0 0 0 0 0 0 0 0 0 0 0 128 0 0 0 0 0 401 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 400 0 0 0 0 0 128 0 0 0 0 0 109 110 111 0 0 0 0 0 128 0 0 0 0 0 401 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 400 0 0 0 0 0 128 0 0 0 0 0 137 138 139 0 0 0 0 0 128 0 0 0 0 0 401 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 400 0 0 0 0 0 128 0 0 0 0 0 165 166 167 0 0 0 0 0 128 0 0 0 0 0 401 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 400 0 0 0 0 0 128 0 0 0 0 0 193 194 195 0 0 0 0 0 128 0 0 0 0 0 401 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 421 369 0 0 0 0 128 0 0 0 0 0 0 0 0 0 0 0 0 0 128 0 0 0 0 368 423 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 449 393 0 0 0 0 128 0 0 0 0 0 0 0 0 0 0 0 0 0 128 0 0 0 0 395 451 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 393 0 0 0 0 156 157 157 157 157 164 0 0 0 156 157 157 157 157 164 0 0 0 0 395 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 393 0 0 0 0 184 185 185 185 185 192 0 0 0 184 185 185 185 185 192 0 0 0 0 395 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 421 422 372 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 373 422 423 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 449 450 400 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 401 450 451 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 421 422 422 422 422 422 372 0 0 0 0 0 0 0 373 422 422 422 422 422 423 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 458 459 460 449 450 450 450 450 450 400 0 0 407 408 409 0 0 401 450 450 450 450 450 451 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 486 487 402 459 459 459 460 0 0 421 422 422 435 436 437 422 422 423 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 486 515 430 487 487 487 402 459 460 449 450 450 463 464 465 450 450 451 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 542 375 515 515 515 515 430 487 488 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 542 543 543 375 515 515 515 488 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 542 543 543 543 544 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 360 361 362 362 362 361 364 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 388 389 390 390 390 389 392 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 416 417 418 418 418 417 420 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
};
string elements1 = {
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 623 624 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 339 0 0 0 0 0 0 654 0 0 0 0 0 0 0 0 0 0 0 651 652 708 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 623 624 0 0 0 0 0 0 325 326 0 0 0 0 591 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 651 652 0 623 624 0 0 0 353 354 0 0 0 0 619 0 0 0 0 679 0 680 0 0 680 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 708 0 651 652 0 0 0 0 0 0 0 0 0 0 0 655 656 0 0 0 0 0 0 0 0 0 0 0 623 624 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 708 678 0 0 572 573 574 0 0 0 0 0 0 683 684 0 0 0 0 0 0 0 0 0 0 0 651 652 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 600 601 602 706 0 0 0 0 0 711 712 681 682 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 572 573 574 572 573 574 0 0 0 0 0 0 0 628 629 630 0 0 0 708 0 0 0 0 709 710 0 0 0 0 679 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 600 601 602 600 601 602 0 0 0 0 0 0 0 706 653 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 325 326 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 628 629 630 628 629 630 0 0 0 0 381 380 0 0 0 0 0 0 0 0 0 0 0 0 680 0 0 623 624 0 353 354 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 380 382 0 382 380 0 0 708 0 0 0 0 0 0 0 0 0 0 0 0 651 652 0 680 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 708 0 0 380 381 623 624 0 567 568 0 0 0 0 0 0 0 0 0 0 0 0 517 518 679 678 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 591 0 651 652 0 595 596 0 0 0 0 0 0 0 0 0 0 0 0 545 546 0 591 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 619 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 567 568 0 0 0 0 619 0 0 0 0 339 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 680 0 0 0 679 0 0 0 0 0 0 0 0 0 0 0 0 0 0 708 595 596 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 680 623 624 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 680 0 0 0 0 0 0 572 573 574 0 0 0 0 0 0 0 572 573 574 0 0 0 0 0 0 0 651 652 0 0 0 0 0 0 0 0 "
"0 0 0 0 339 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 600 601 602 0 0 0 0 0 0 0 600 601 602 0 0 0 0 0 0 341 0 591 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 708 0 0 0 0 0 0 0 0 628 629 630 0 0 0 0 0 0 0 628 629 630 0 0 0 0 0 572 573 574 619 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 339 600 601 602 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 680 0 0 0 0 680 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 628 629 630 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 339 341 0 0 0 0 0 0 0 0 0 341 680 0 0 0 0 680 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 708 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 679 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 680 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 708 0 0 0 0 0 0 0 0 708 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 708 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 679 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 339 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 679 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 708 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 340 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 680 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"517 518 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 339 0 0 0 0 0 0 0 680 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"545 546 0 0 517 518 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 680 708 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 545 546 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
};
string trees = {
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 86 87 88 89 0 0 90 91 92 93 94 95 96 97 98 0 0 0 0 0 86 87 88 89 0 30 31 32 33 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 114 115 116 117 0 0 118 119 120 121 122 123 124 125 126 0 0 0 0 0 114 115 116 117 0 58 59 60 61 0 0 0 "
"0 0 0 0 0 0 0 0 30 31 32 33 0 0 0 0 0 0 142 143 144 145 0 0 146 147 148 149 150 151 152 153 154 0 0 0 0 0 142 143 144 145 0 86 87 88 89 0 0 0 "
"0 0 0 0 0 0 0 0 58 59 60 61 0 0 0 0 0 0 170 171 172 173 0 0 174 175 176 177 178 179 180 181 182 0 30 31 32 33 170 171 172 173 0 114 115 116 117 0 0 0 "
"0 0 0 0 0 0 0 0 86 87 88 89 0 0 0 0 0 0 198 199 200 201 0 0 202 203 204 205 206 207 208 209 210 0 58 59 60 61 198 199 200 201 0 142 143 144 145 0 0 0 "
"0 0 0 0 0 0 0 0 114 115 116 117 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 86 87 88 89 0 0 0 0 0 170 171 172 173 0 0 0 "
"0 0 0 0 0 0 0 0 142 143 144 145 0 470 471 472 473 474 475 476 0 0 0 0 0 0 0 0 0 0 0 0 0 0 114 115 116 117 0 0 0 0 0 198 199 200 201 0 0 0 "
"0 0 0 0 0 0 0 0 170 171 172 173 0 498 499 500 501 502 503 504 0 0 0 0 0 0 0 0 0 0 0 0 0 0 142 143 144 145 0 0 30 31 32 33 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 198 199 200 201 0 526 527 528 529 530 531 532 0 0 0 0 0 0 0 0 0 0 0 0 0 0 170 171 172 173 0 0 58 59 60 61 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 554 555 556 557 558 559 560 0 0 0 0 0 0 0 0 0 0 0 0 0 0 198 199 200 201 0 0 86 87 88 89 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 582 583 584 585 586 587 588 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 114 115 116 117 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 610 611 612 613 614 615 616 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 142 143 144 145 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 638 639 640 641 642 643 644 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 170 171 172 173 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 30 31 32 33 0 0 0 0 0 0 0 0 0 0 0 0 0 30 31 32 33 0 0 0 198 199 200 201 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 58 59 60 61 0 0 0 0 0 0 0 0 0 0 0 0 0 58 59 60 61 0 0 0 0 0 30 31 32 33 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 86 87 88 89 0 0 0 0 0 0 0 0 0 0 0 0 0 86 87 88 89 0 0 0 0 0 58 59 60 61 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 114 115 116 117 0 0 0 0 0 0 0 0 0 0 0 0 0 114 115 116 117 0 0 0 0 0 86 87 88 89 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 142 143 144 145 0 0 0 0 0 0 0 0 0 0 0 0 0 142 143 144 145 0 0 0 0 0 114 115 116 117 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 170 171 172 173 0 0 0 0 0 0 0 0 0 0 0 0 0 170 171 172 173 0 0 0 0 0 142 143 144 145 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 198 199 200 201 0 0 0 0 0 0 0 0 0 0 0 0 0 198 199 200 201 0 0 0 0 0 170 171 172 173 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 198 199 200 201 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 466 467 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"491 492 493 494 495 496 497 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"519 520 521 522 523 524 525 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"547 548 549 550 551 552 553 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"575 576 577 578 579 580 581 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"603 604 605 606 607 608 609 30 31 32 33 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"631 632 633 634 635 636 637 58 59 60 61 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 86 87 88 89 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 114 115 116 117 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 142 143 144 145 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
};
string elements2 = {
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 657 658 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 685 686 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 713 714 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 340 0 339 340 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 572 573 574 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 600 601 602 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 628 629 630 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
};
string mapBorders = {
"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,728,728,728,728,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,728,0,0,0,0,0,728,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,728,728,0,0,0,0,0,0,0,0,728,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,0,728,728,728,728,0,0,0,0,0,0,0,0,0,0,0,728,728,0,0,0,0,0,0,0,0,0,0,0,0,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,0,728,0,0,728,728,728,728,728,728,728,0,0,0,0,0,728,0,0,0,0,0,0,728,0,0,0,0,0,0,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,728,728,0,0,0,0,0,0,0,0,728,0,0,0,0,0,728,0,0,0,0,0,728,728,728,0,0,0,0,0,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,728,0,0,0,0,0,0,0,0,0,728,0,0,0,0,0,728,728,728,0,0,0,728,728,728,0,0,0,0,0,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,728,728,0,0,0,0,0,0,0,0,0,728,0,0,0,0,0,728,728,728,0,0,0,0,0,0,0,0,0,0,0,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,728,0,0,0,0,0,0,0,0,0,0,728,0,0,0,0,0,728,0,0,0,0,0,0,0,0,0,0,0,728,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,728,0,0,0,0,0,0,0,0,0,0,728,728,0,0,0,0,728,0,0,0,0,0,0,0,0,0,0,0,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,728,0,0,0,0,0,0,0,0,0,0,0,728,0,0,0,0,728,728,728,728,728,728,0,0,0,728,728,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,728,0,0,0,0,0,0,0,0,0,0,0,728,0,0,0,0,0,0,0,728,728,728,0,0,0,728,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,728,0,0,0,0,0,0,0,0,0,0,0,728,0,0,0,0,0,0,0,728,0,0,0,0,0,0,0,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,728,0,0,0,0,0,0,0,0,0,0,0,728,728,728,0,0,0,0,0,728,0,0,0,0,0,0,0,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,728,0,0,0,0,0,0,0,0,0,0,0,0,0,728,0,0,0,0,0,728,0,0,0,0,0,0,0,728,0,0,0,0,0,728,728,728,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,728,0,0,0,0,0,0,0,0,0,0,0,0,0,728,0,0,0,0,0,728,0,0,0,0,0,0,0,728,728,728,728,728,728,728,0,728,728,728,0,0,0,0,0,0,0,0,0,"
"0,0,728,0,0,0,0,0,0,0,0,0,0,0,728,728,728,0,0,0,0,0,728,728,728,0,0,0,728,728,728,0,0,0,0,0,0,0,0,0,728,728,728,728,0,0,0,0,0,0,"
"0,0,728,0,0,0,0,0,0,0,0,0,0,0,728,728,0,0,0,0,728,728,728,728,728,0,0,0,728,728,728,0,0,0,0,0,0,0,0,0,0,0,0,728,0,0,0,0,0,0,"
"0,0,728,728,0,0,0,0,0,0,0,0,0,0,0,728,728,728,728,0,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,0,0,0,0,0,0,"
"0,0,0,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,0,0,0,0,0,0,"
"0,0,0,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,728,0,0,0,0,0,0,"
"0,0,0,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,0,0,0,0,0,0,0,"
"0,0,0,0,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,728,728,728,0,0,0,0,"
"0,0,0,0,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,0,0,0,0,"
"0,0,0,0,0,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,0,0,0,0,"
"0,0,0,0,0,728,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,728,728,728,728,728,728,728,0,0,0,0,"
"0,0,0,0,0,0,0,728,728,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,728,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,0,0,0,0,0,0,0,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,728,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,0,0,0,0,0,0,0,0,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,728,728,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,0,0,0,0,0,0,0,0,0,728,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,728,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,728,728,0,0,0,0,0,0,0,0,0,0,728,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,728,728,728,0,0,0,0,0,728,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"
"0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,728,728,728,728,728,728,728,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0"

};

Tilemap::Tilemap(int dim)
{
    mapTexture.loadFromFile("assets/mapTexture.png");
    loadTileSet();
    grassLayer = loadLayer(dim, grass);
    groundLayer = loadLayer(dim, ground);
    worldLayer = loadLayer(dim, world);
    elements1Layer = loadLayer(dim, elements1);
    treesLayer = loadLayer(dim, trees);
    elements2Layer = loadLayer(dim, elements2);
    mapBordersLayer = loadLayer(dim, mapBorders);
}
Tilemap::~Tilemap()
{
}


void Tilemap::loadTileSet()
{
    int columns = 28;
    for (int id = 0; id < 728; id++)
    {
        tileOffsets.push_back({ id % columns, id / columns });
    }
}


std::vector<sf::Sprite> Tilemap::loadLayer(int dim, string s)
{
    int j = 0;
    int k = 0;
    vector<Sprite> result;
    vector<int> tmp = split(s);

    for (int i = 0; i < tmp.size(); i++)
    {
        Sprite s = loadTile(dim, tmp[i]);
        s.setPosition(dim * k, dim * j);
        result.push_back(s);
        k += 1;
        if (k >= 50)
        {
            k = 0;
            j += 1;
        }
    }
    return result;
}


Sprite Tilemap::loadTile(int dim, int i)
{
    Sprite sprite;
    if (i != 0)
    {
        i--;
        sprite.setTexture(mapTexture);
        sf::IntRect rect({ (tileOffsets[i]).x * dim, (tileOffsets[i]).y * dim }, { dim,dim });
        sprite.Sprite::setTextureRect(rect);
    }
    return sprite;
}


vector<int> Tilemap::split(string s)
{
    vector<int> tmpVect;

    stringstream ss(s);

    for (int i; ss >> i;) {
        tmpVect.push_back(i);
        if (ss.peek() == ',')
        {
            ss.ignore();
        }
    }
    return tmpVect;
}

std::vector<sf::Sprite> Tilemap::getMapBorders()
{
    return mapBordersLayer;
}

void Tilemap::drawTilemap(RenderWindow& rw)
{
    for (int i = 0; i < grassLayer.size(); i++)
    {
        rw.draw(grassLayer[i]);
    }
    for (int i = 0; i < groundLayer.size(); i++)
    {
        rw.draw(groundLayer[i]);
    }
    for (int i = 0; i < worldLayer.size(); i++)
    {
        rw.draw(worldLayer[i]);
    }
    for (int i = 0; i < elements1Layer.size(); i++)
    {
        rw.draw(elements1Layer[i]);
    }
    for (int i = 0; i < treesLayer.size(); i++)
    {
        rw.draw(treesLayer[i]);
    }
    for (int i = 0; i < elements2Layer.size(); i++)
    {
        rw.draw(elements2Layer[i]);
    }
}
void Tilemap::drawMapBorders(RenderWindow& rw)
{
    for (int i = 0; i < mapBordersLayer.size(); i++)
    {
        rw.draw(mapBordersLayer[i]);
    }
}


