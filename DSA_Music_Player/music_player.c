#include "queue.h"
#include "dll.h"
#include "music_player.h"
#include <stdio.h>
#include <stdlib.h>

int searchint = 0;

playlist_t *create_playlist() // return a newly created doubly linked list
{
	// DO NOT MODIFY!!!
	playlist_t *playlist = (playlist_t *)malloc(sizeof(playlist_t));
	playlist->list = create_list();
	playlist->num_songs = 0;
	playlist->last_song = NULL;
	return playlist;
}

void delete_playlist(playlist_t *playlist) // delete the playlist
{
	// DO NOT MODIFY!!!
	delete_list(playlist->list);
	free(playlist);
}

music_queue_t *create_music_queue() // return a newly created queue
{
	// DO NOT MODIFY!!!
	return create_queue();
}

void clear_music_queue(music_queue_t *q) // clear the queue q
{
	// DO NOT MODIFY!!!
	delete_queue(q);
}

void add_song(playlist_t *playlist, int song_id, int where) // TODO: add a song id to the end of the playlist
{
	if (where == -2)
	{
		insert_back(playlist->list, song_id);
		playlist->num_songs += 1;
	}
	else if (where == -1)
	{
		insert_front(playlist->list, song_id);
		playlist->num_songs += 1;
	}
	else if (where >= 0)
	{
		insert_after(playlist->list, song_id, where);
		playlist->num_songs += 1;
	}
}

void delete_song(playlist_t *playlist, int song_id) // TODO: remove song id from the playlist
{
	delete_node(playlist->list,song_id);
	if((playlist->last_song!=NULL)&&(playlist->last_song->data==song_id))
	{
		playlist->last_song=NULL;
	}
	if(search_song(playlist,song_id))
	{
		playlist->num_songs--;
	}
}

song_t *search_song(playlist_t *playlist, int song_id) // TODO: return a pointer to the node where the song id is present in the playlist
{
	return (search(playlist->list, song_id));
}

void search_and_play(playlist_t *playlist, int song_id) // TODO: play the song with given song_id from the list(no need to bother about the queue. Call to this function should always play the given song and further calls to play_next and play_previous)
{
	song_t *temp = playlist->list->head;
	while (temp != NULL)
	{
		if (temp->data == song_id)
		{
			play_song(temp->data);
			playlist->last_song = temp;
			break;
		}
		temp = temp->next;
	}
}

void play_next(playlist_t *playlist, music_queue_t *q) // TODO: play the next song in the linked list if the queue is empty. If the queue is not empty, play from the queue
{
	if ((q->front == NULL) && (playlist->list->head == NULL))
	{
		return;
	}
	else if ((playlist->list->head != NULL) && (q->front == NULL))
	{
		if (playlist->last_song == NULL)
		{
			playlist->last_song = playlist->list->head;
			play_song(playlist->last_song->data);
			return;
		}
		else
		{
			song_t *current = playlist->last_song;
			if (current->next == NULL)
			{
				playlist->last_song = playlist->list->head;
			}
			else
			{
				playlist->last_song = playlist->last_song->next;
			}
			search_and_play(playlist, playlist->last_song->data);
		}
	}
	else
	{
		if (playlist->last_song == NULL)
		{
			playlist->last_song = playlist->list->head;
			play_song(playlist->last_song->data);
			return;
		}
		else
		{
			play_song(dequeue(q));
		}
	}
}

void play_previous(playlist_t *playlist) // TODO: play the previous song from the linked list
{
	if (playlist->list->head == NULL)
	{
		return;
	}
	if (playlist->last_song == NULL)
	{
		playlist->last_song = playlist->list->tail;
		play_song(playlist->last_song->data);
	}
	else if (playlist->last_song->prev == NULL)
	{
		if (searchint == 1)
		{
			play_song(playlist->last_song->data);
			searchint = 0;
		}
		else
		{
			playlist->last_song = playlist->list->tail;
			play_song(playlist->last_song->data);
		}
	}
	else
	{
		if (searchint == 1)
		{
			play_song(playlist->last_song->data);
			searchint = 0;
		}
		else
		{
			playlist->last_song = playlist->last_song->prev;
			play_song(playlist->last_song->data);
		}
	}
}

void play_from_queue(music_queue_t *q) // TODO: play a song from the queue
{
	play_song(dequeue(q));
}

void insert_to_queue(music_queue_t *q, int song_id) // TODO: insert a song id to the queue
{
	enqueue(q, song_id);
}

void reverse(playlist_t *playlist) // TODO: reverse the order of the songs in the given playlist. (Swap the nodes, not data)
{
	song_t *p = playlist->list->head;
	song_t *temp = NULL;
	if (p == NULL)
	{
		return;
	}
	while (p != NULL)
	{
		temp = p->prev;
		p->prev = p->next;
		p->next = temp;
		p = p->prev;
	}
	if (temp != NULL)
	{
		playlist->list->head = temp->prev;
		p = playlist->list->head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		playlist->list->tail = p;
	}
}

void k_swap(playlist_t *playlist, int k) // TODO: swap the node at position i with node at position i+k upto the point where i+k is less than the size of the linked list
{
	if (playlist->list->head == NULL)
	{
		return;
	}
	else if ((playlist->list->head) == (playlist->list->tail))
	{
		return;
	}
	else if (k == 1)
	{
		song_t *temp = playlist->list->head;
		temp->next->prev = NULL;
		playlist->list->head = temp->next;
		temp->prev = playlist->list->tail;
		playlist->list->tail->next = temp;
		temp->next = NULL;
	}
	else
	{
		for (int i = 0; (k + i) < playlist->list->size; i++)
		{
			int k1 = 0, k2 = 0;
			song_t *temp1 = playlist->list->head;
			song_t *temp2 = playlist->list->head;
			while (k1 != i)
			{
				temp1 = temp1->next;
				k1++;
			}
			while (k2 != (i + k))
			{
				temp2 = temp2->next;
				k2++;
			}
			song_t *temp1prev = temp1->prev;
			song_t *temp1next = temp1->next;
			if (temp1 == playlist->list->head)
			{
				playlist->list->head = temp2;
			}
			if (temp2 == playlist->list->tail)
			{
				playlist->list->tail = temp1;
			}
			temp1->prev = temp2->prev;
			temp1->next = temp2->next;
			temp2->prev = temp1prev;
			temp2->next = temp1next;
			if (temp1->next != NULL)
			{
				temp1->next->prev = temp1;
			}
			if (temp2->next != NULL)
			{
				temp2->next->prev = temp2;
			}
			if (temp2->prev != NULL)
			{
				temp2->prev->next = temp2;
			}
			if (temp1->prev != NULL)
			{
				temp1->prev->next = temp1;
			}
		}
	}
}

void shuffle(playlist_t *playlist, int k) // TODO: perform k_swap and reverse
{
	if (playlist->list->head != NULL)
	{
		k_swap(playlist, k);
		reverse(playlist);
	}
}

song_t *debug(playlist_t *playlist) // TODO: if the given linked list has a cycle, return the start of the cycle, else return null. Check cycles only in forward direction i.e with the next pointer. No need to check for cycles in the backward pointer.
{
	return playlist->list->tail->next;
}

void display_playlist(playlist_t *p) // Displays the playlist
{
	// DO NOT MODIFY!!!
	display_list(p->list);
}

void play_song(int song_id)
{
	// DO NOT MODIFY!!!
	printf("Playing: %d\n", song_id);
}