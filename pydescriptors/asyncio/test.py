import asyncio

async def say_hello():
  print('Hello')
  await asyncio.sleep(3)
  print('World')
  return asyncio.get_event_loop()

async def say_good_bye():
  print('Good')
  await asyncio.sleep(2)
  print('Bye')

event_loop = asyncio.get_event_loop()
event_loop.run_until_complete(say_good_bye())
event_loop.run_until_complete(say_hello())

event_loop.close()
