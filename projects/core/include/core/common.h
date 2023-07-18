/**
 * @file Common.h
 * @author Dmitrii Ivanov (idma88@yandex.ru)
 * @brief Определение общих перечислений, псевдонимов и констант
 */
#pragma once

#include <cstdint>

namespace OpenIT {
/**
 * @brief Координаты
 */
struct Position
{
  /// Горизонтальная координата
  int8_t x;
  /// Вертикальная координата
  int8_t y;
};

/// Псевдоним типа для уникальных идентификаторов
using IdValue = uint64_t;
/// Псевдоним типа для значений ячеек
using CellValue = int8_t;
/// Псевдоним типа для счёта игрока
using ScoreValue = int16_t;

/// Количество игроков
static const uint8_t PLAYER_COUNT = 2;
/// Размер игрового поля
static const uint8_t FIELD_SIZE = 8;
/// Минимальное значение в ячейке
static const CellValue ABS_MIN_VALUE = 1;
/// Максимальное значение в ячейке
static const CellValue ABS_MAX_VALUE = 11;

} // namespace OpenIT