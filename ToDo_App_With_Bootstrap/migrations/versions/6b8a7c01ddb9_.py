"""empty message

Revision ID: 6b8a7c01ddb9
Revises: 
Create Date: 2022-11-26 11:06:29.857081

"""
from alembic import op
import sqlalchemy as sa


# revision identifiers, used by Alembic.
revision = '6b8a7c01ddb9'
down_revision = None
branch_labels = None
depends_on = None


def upgrade():
    # ### commands auto generated by Alembic - please adjust! ###
    op.add_column('note', sa.Column('color', sa.String(length=10), nullable=True))
    # ### end Alembic commands ###


def downgrade():
    # ### commands auto generated by Alembic - please adjust! ###
    op.drop_column('note', 'color')
    # ### end Alembic commands ###