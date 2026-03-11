from fastapi import FastAPI
from pydantic import BaseModel
from llama_service import ask_llm

app = FastAPI()

class ChatRequest(BaseModel):
    message: str

@app.post("/chat")
def chat(req: ChatRequest):

    answer = ask_llm(req.message)

    return {
        "response": answer
    }