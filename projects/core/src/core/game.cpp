#include <ctime> // rand()

#include <game.h>

namespace OpenIT {

CellValue
Game::GenerateCellValue()
{
  /// random_number = firs_value + rand() % last_value;
  CellValue value;
  do {
    value      = ABS_MIN_VALUE + rand() % ABS_MAX_VALUE;
    bool sight = rand() % 1;
    value      = sight ? value : value * -1;
  } while (CheckRepeatValue(value));
  return value;
}

bool
Game::CheckRepeatValue(CellValue value)
{
  size_t count = 0;
  for (size_t i = 0; i < FIELD_SIZE * FIELD_SIZE; ++i) {
    if (value == m_field[i]) ++count;
    if (count >= MAX_REPEAT_VALUE) return true;
  }
  return false;
}

Game::Game()
{
  std::srand(std::time(nullptr));
  // Start(); //?
  // TODO Game::Game()
}

void
Game::Start()
{
  // TODO void Game::Start()

  m_field.fill(0);

  for (size_t i = 0; i < FIELD_SIZE * FIELD_SIZE; ++i)
    m_field[i] = GenerateCellValue();

  if (!m_players.empty()) {
    for (auto it = m_players.begin(); it != m_players.end(); ++it) {
      it->m_score = 0;
    }
  }

  // Стартовая позиция каретки
  // TODO Уточнить стартовую поз
  m_carriage.x = rand() % FIELD_SIZE;
  m_carriage.y = rand() % FIELD_SIZE;

  // Стартовый выбор активного игрока
  // TODO Уточнить принцип выбора активного игрока
  m_activePlayer = rand() % 2;
}

bool
Game::IsGameOver() const
{
  // TODO bool Game::IsGameOver() const
  int summCell = 0;
  // Вертикальное перемещение каретки для игрока №1
  if (m_activePlayer == 0)
    for (int y = 0; y < FIELD_SIZE; ++y)
      summCell += m_field[m_carriage.x + y * FIELD_SIZE];

  //Горизонтальное перемещение каретки для игрока №2
  else
    for (int x = 0; x < FIELD_SIZE; ++x)
      summCell += m_field[x + m_carriage.y * FIELD_SIZE];

  return !summCell;
}

IdValue
Game::GetId() const
{
  return m_id;
}

Players
Game::GetPlayers() const
{
  return m_players;
}

uint8_t
Game::GetActivePlayer() const
{
  return m_activePlayer;
}

Scores
Game::GetScores() const
{
  // TODO Scores Game::GetScores() const
  Scores scores;
  for (auto it = m_players.begin(); it != m_players.end(); ++it) {
    scores.push_back(*it.m_score);
  }
}

Field
Game::GetField() const
{
  return m_field;
}

Position
Game::GetCarriage() const
{
  return m_carriage;
}

bool
Game::AddPlayer(const Player& player)
{
  if (m_players.size() == 2) return false;

  m_players.push_back(player);

  return true;
}

bool
Game::RemovePlayer(uint8_t index)
{
  if (m_players.empty()) return false;

  if (m_players.size() - 1 < index) return false;

  m_players.erase(index);

  return true;
}

Position
Game::MoveCarriage(Position pos)
{
  // TODO Position Game::MoveCarriage(Position pos)
  // Вертикальное перемещение каретки для игрока №1
  if (m_activePlayer == 0) {
    if (pos.x == m_carriage.x && pos.y >= 0 && pos.y < FIELD_SIZE) m_carriage = pos;
  }
  //Горизонтальное перемещение каретки для игрока №2
  else {
    if (pos.y == m_carriage.y && pos.x >= 0 && pos.x < FIELD_SIZE) m_carriage = pos;
  }
  return m_carriage;
}

bool
Game::OpenCell()
{
  // TODO bool Game::OpenCell()

  int cellPos = m_carriage.x + m_carriage.y * FIELD_SIZE;
  if (m_field[cellPos] != 0) {
    if (m_activePlayer == 0)
      m_players.front().m_score += m_field[cellPos];
    else
      m_players.back().m_score += m_field[cellPos];

    m_field[cellPos] = 0;

    m_activePlayer = (m_activePlayer ? 0 : 1);

    return true;
  }
  return false;
}

} // namespace OpenIT