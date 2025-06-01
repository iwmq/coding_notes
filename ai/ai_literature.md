Notes of select papers on AI, just for fun.

Out of curiosity, I have been reading some interesting papers about AI since
2018. Early readings were on object classification from images using CNN which
turns out not much useful and faded away from everybody's talking. From 2024,
I noticed affordable and more useful applications of LLMs which is my current
hobby.

Here I put findings, confusions and thoughts on my favorite papers. They will
be easy, and the count should be less than 10.


#1: Language models are few-shot learners
---
URL: https://arxiv.org/abs/2005.14165

GPT-3 with 175B parameters is able to do various NLP tasks and outperforms many
fine-tuned models.

As a foundation model, what GPT-3 can do is to complete a given sentence. If
the provided prompt is k examples plus a sentence to be completed, it's output
follows the format of the given example. Such a prompt is called k-shot. k = 1
means on-shot, k = 0 (no example) is zero-shot.

The ability to learn from examples in inference is called in-contenxt learning
and the model's weight won't be updated.


#2: Training language models to follow instructions with human feedback
---
URL: https://arxiv.org/abs/2203.02155

From the pre-trained foundation model GPT-3, task-specific models can be fine-tunned
with less examples. So resulting models can do more useful tasks.


#3: SWE-agent: Agent-Computer Interfaces Enable Automated Software Engineering
---
URL: https://arxiv.org/abs/2405.15793

As language models evolved, their most promising application is coding.

A LLM can use tools to observe and change environment which is code repositories.
Interacting with code requires a new category of efficient interface, called
agent-computer interface (ACI) which consists of tools to look up files, search
terms in files, create and edit files, run scripts, etc.

The paper descibes a LLM agent which can fixes selected issues from widely used
Python libraries. To fix an issue, the agent read the issue description, use a
series of steps to reproduce it, update files, test it, then commit the change
if it succeeds or give up if it runs out of budget. The series of steps to fix
a issue is called a trajectory.

The proposed ACI is a good description of currently popular agentic coding.


#4: BOND Capital AI Trends report
---
URL: https://www.bondcap.com/reports/tai

Mary Meeker's report on trends of AI. The 340 slides summerize statistics and
facts of AI. The digrams are beautiful.

This is not a technical report, but I did learn new knowledge from it.