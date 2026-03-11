from llama_index.llms.ollama import Ollama

llm = Ollama(model="llama3")

def ask_llm(message: str):

    prompt = f"""
    너는 게임 NPC다.

    플레이어: {message}
    NPC:
    """

    response = llm.complete(prompt)

    return str(response)