import asyncio 

async def get_item(i):
  print(f"For {i}")
  await asyncio.sleep(i)
  print(f"Sleep Completed for {i}")

async def get_items(num_items):
  print(f"Number of items: {num_items}")

  # create list of coroutines as tasks
  tasks = [asyncio.create_task(get_item(6-i)) for i in range(1, num_items+1)]
  print(f"Tasks: {tasks}")
  
  # wait for tasks to complete
  print('Waiting for tasks to be completed...')
  completed_tasks, pending_tasks = await asyncio.wait(tasks, timeout=3)
  print(f"Completed tasks: {completed_tasks}, pending tasks: {pending_tasks}")

  # access results of the completed tasks
  results = [task.result() for task in completed_tasks]
  print(f"Results of the completed tasks: {results}")
  print(f"Pending tasks: {pending_tasks}")


asyncio.run(get_items(4))
exit()
# create event loop
event_loop = asyncio.get_event_loop()

try:
  # execute the coroutine in the event loop
  print('Starting event loop..')
  event_loop.run_until_complete(get_items(4))
  print('Completed event loop!')
except Exception as e:
  print(f"Exception happend: {e}")
finally:
  event_loop.close()

