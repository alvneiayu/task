static
int nft_rule_exp_target_snprintf_json(char *buf, size_t len,
				struct nft_expr_target *tg)
{
	int ret, size=len;
	int i;
	int offset = 0;
	uint8_t *data = (uint8_t *)tg->data;

	ret = snprintf(buf, len, "\"name\" : \"%s\",\"rev\" : %u,\"info\" : \"0x",
			tg->name, tg->rev);
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	for (i=0; i < tg->data_len; i++) {
		ret = snprintf(buf+offset, len, "%x", data[i] & 0xff);
		SNPRINTF_BUFFER_SIZE(ret, size, len, offset);
	}

	ret = snprintf(buf+offset, len, "\"");
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	return offset;
}
