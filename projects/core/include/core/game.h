/**
 * @file Game.h
 * @author Dmitrii Ivanov (idma88@yandex.ru)
 * @brief Определение класса Игра
 */
#pragma once

#include <array>
#include <cstdint>
#include <list>

#include <core/common.h>
#include <core/player.h>

namespace OpenIT {
/**
 * @brief Игра
 */
class Game
{
public:
  /// Псевдоним типа игроков
  using Players = std::list<Player>;
  /// Псевдоним типа игрового поля
  using Field = std::array<CellValue, FIELD_SIZE * FIELD_SIZE>;
  /// Псевдоним счётов игроков
  using Scores = std::list<ScoreValue>;

public:
  /**
   * @brief Конструктор
   */
  Game();

  /**
   * @brief Деструктор
   */
  ~Game() = default;

  /**
   * @brief Начинает новую игру
   *
   * Формирует новое поле, сбрасывает счёта игроков, устанавливает активного игрока и
   * начальную позицию позицию каретки
   */
  void Start();

  /**
   * @brief Сообщает состояние окончания игры
   *
   * Игра считается оконченной, если активный игрок не имеет возможности сделать очередной ход.
   *
   * @return Возвращает true, если игра окончана или false в противном случае
   */
  bool IsGameOver() const;

  /**
   * @brief Получает идентификатор игры
   *
   * @return Возвращает идентификатор игры
   */
  IdValue GetId() const;

  /**
   * @brief Получает список игроков
   *
   * @return Возвращает список игроков
   */
  Players GetPlayers() const;

  /**
   * @brief Получает номер активного игрока
   *
   * @return Возвращает номер активного игрока
   */
  uint8_t GetActivePlayer() const;

  /**
   * @brief Получает счета игроков
   *
   * @return Возвращает счета игроков
   */
  Scores GetScores() const;

  /**
   * @brief Предоставляет содержимое игрового поля
   *
   * @return Возвращает содержимое игрового поля
   */
  Field GetField() const;

  /**
   * @brief Получает позицию каретки
   *
   * @return Возвращает позицию каретки
   */
  Position GetCarriage() const;

  /**
   * @brief Добавляет игрока в список
   *
   * @param[in] player Игрок
   * @return Возвращает true в случае успеха или false в противном случае
   */
  bool AddPlayer(const Player& player);

  /**
   * @brief Удаляет игрока из списка
   *
   * @param[in] index Порядковый номер игрока в списке
   * @return Возвращает true в случае успеха или false в противном случае
   */
  bool RemovePlayer(uint8_t index);

  /**
   * @brief Перемещает каретку в указанную позицию
   *
   * Метод проверяет допустимость перемещения каредки в указанную позицию с учётом активного игрока
   * и доступного ему направления движения каретки.
   * Если перемещение недоступно, но поция каретки не изменяется.
   *
   * @param[in] pos Позиция коретки
   * @return Возвращает новую позицию каретки
   */
  Position MoveCarriage(Position pos);

  /**
   * @brief Открывает ячейку под кареткой
   *
   * Количество очков из ячейки зачисляется на счёт активного игрока после чего ход передается
   * другому игроку.
   * Для ранее открытой ячейки зачисление очков и передача хода не производится.
   *
   * @return Возвращает true в случае успеха или false в противном случае
   */
  bool OpenCell();

private:
  /**
   * @brief Заполение ячейки случайным числом из диапазона [-11; -1]и[1; 11]
   *
   * @return Значение ячейки
   */
  CellValue GenerateCellValue();

  /**
   * @brief Проверка повторного вхождения значения ячейки. Не более 3 раз.
   *
   * @param value Новое значение для заполения ячейки
   * @return Если вхождений меньше 3 возвращает FALSE, иначе TRUE
   */
  bool CheckRepeatValue(CellValue value);

private:
  /// Идентификатор игры
  IdValue m_id;
  /// Список игроков
  Players m_players;
  /// Номер активного игрока
  uint8_t m_activePlayer;
  /// Игровое поле
  Field m_field;
  /// Координаты каретки
  Position m_carriage;
};
} // namespace OpenIT