/*
    _____               __  ___          __            ____        _      __
   / ___/__ ___ _  ___ /  |/  /__  ___  / /_____ __ __/ __/_______(_)__  / /_
  / (_ / _ `/  ' \/ -_) /|_/ / _ \/ _ \/  '_/ -_) // /\ \/ __/ __/ / _ \/ __/
  \___/\_,_/_/_/_/\__/_/  /_/\___/_//_/_/\_\\__/\_, /___/\__/_/ /_/ .__/\__/
                                               /___/             /_/
                                             
  See Copyright Notice in gmMachine.h

*/

#include "gmConfig.h"
#include "gmStreamBuffer.h"


gmStreamBufferStatic::gmStreamBufferStatic()
{
  m_cursor = 0;
  m_size = 0;
  m_stream = NULL;
}


gmStreamBufferStatic::gmStreamBufferStatic(const void * p_buffer, gmint a_size)
{
  Open(p_buffer, a_size);
}


gmStreamBufferStatic::~gmStreamBufferStatic()
{
}


gmint gmStreamBufferStatic::Seek(gmint p_pos)
{
  gmint oldCursor = m_cursor;
  gmint cursor = p_pos;
  if(cursor < 0) return (gmint)ILLEGAL_POS;
  if((gmint) cursor > m_size) return (gmint)ILLEGAL_POS;
  m_cursor = cursor;
  return oldCursor;  
}


gmint gmStreamBufferStatic::Tell() const
{
  return m_cursor;
}


gmint gmStreamBufferStatic::GetSize() const
{
  return m_size;
}


gmint gmStreamBufferStatic::Read(void * p_buffer, gmint p_n)
{
  gmint remain = m_size - m_cursor;
  if(p_n > remain)
  {
    m_flags |= F_EOS;
    p_n = remain;
  }
  memcpy(p_buffer, &m_stream[m_cursor], p_n);
  m_cursor += p_n;
  return p_n;
}


gmint gmStreamBufferStatic::Write(const void * p_buffer, gmint p_n)
{
  m_flags |= F_ERROR;
  return 0;
}


void gmStreamBufferStatic::Open(const void * p_buffer, gmint a_size)
{
  m_cursor = 0;
  m_size = a_size;
  m_stream = (const char *) p_buffer;
  m_flags = F_READ | F_SIZE | F_SEEK | F_TELL;
}


//
// gmStreamBufferDynamic
//


gmStreamBufferDynamic::gmStreamBufferDynamic()
{
  m_cursor = 0;
  m_flags = F_READ | F_WRITE | F_SIZE | F_SEEK | F_TELL;
}


gmStreamBufferDynamic::~gmStreamBufferDynamic()
{
}


gmint gmStreamBufferDynamic::Seek(gmint p_pos)
{
  gmint oldCursor = m_cursor;
  gmint cursor = p_pos;
  if(cursor < 0) 
    return (gmint)ILLEGAL_POS;
  if(cursor > m_stream.Count()) 
    return (gmint)ILLEGAL_POS;
  m_cursor = cursor;
  return oldCursor;
}


gmint gmStreamBufferDynamic::Tell() const
{
  return m_cursor;
}


gmint gmStreamBufferDynamic::GetSize() const
{
  return m_stream.Count();
}


gmint gmStreamBufferDynamic::Read(void * p_buffer, gmint p_n)
{
  gmint remain = m_stream.Count() - m_cursor;
  if(p_n > remain)
  {
    // set eof
    m_flags |= F_EOS;
    p_n = remain;
  }
  memcpy(p_buffer, m_stream.GetData() + m_cursor, p_n);
  m_cursor += p_n;
  return p_n;
}


gmint gmStreamBufferDynamic::Write(const void * p_buffer, gmint p_n)
{
  gmint remain = m_stream.Count() - m_cursor;
  if(p_n > remain)
  {
    // grow the stream
    m_stream.SetCount(m_cursor + p_n);
  }
  memcpy(m_stream.GetData() + m_cursor, p_buffer, p_n);
  m_cursor += p_n;
  return p_n;
}


void gmStreamBufferDynamic::Reset()
{
  m_cursor = 0;
  m_flags = F_READ | F_WRITE | F_SIZE | F_SEEK | F_TELL;
  m_stream.Reset();
}


void gmStreamBufferDynamic::ResetAndFreeMemory()
{
  m_cursor = 0;
  m_flags = F_READ | F_WRITE | F_SIZE | F_SEEK | F_TELL;
  m_stream.ResetAndFreeMemory();
}

