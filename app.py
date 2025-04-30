import streamlit as st
import csv
import re
import pandas as pd

def validate_email(email):
    """Validate the email address"""
    pattern = r"^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$"
    return bool(re.match(pattern, email))

def submit_form(description, email):
    """Submit the form data to the CSV file"""
    data = {'Description': [description], 'Email': [email]}
    df = pd.DataFrame(data)
    try:
        existing_df = pd.read_csv('user_requests.csv')
        combined_df = pd.concat([existing_df, df])
        combined_df.to_csv('user_requests.csv', index=False)
    except FileNotFoundError:
        df.to_csv('user_requests.csv', index=False)

def ask_me_a_question_form():
    """The 'Ask me a question' form"""
    st.subheader("Ask me a question:")
    description = st.text_area(label="A description of why you're reaching out, including any questions you have")
    email = st.text_input(label="What email can I reach you at?")

    submitted = st.form_submit_button("Submit")

    if submitted:
        if not validate_email(email):
            st.error("Invalid email address")
        else:
            submit_form(description, email)
            st.success("Thank you for your submission!")

def main():
    st.title("My Small Business")
    st.subheader("Description of my small business", divider="violet")

    with st.form("Ask me a question:", clear_on_submit=True):
        ask_me_a_question_form()

if __name__ == "__main__":
    main()
